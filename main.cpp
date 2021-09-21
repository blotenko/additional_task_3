// Two  sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
            for(int j = 0; j<nums.size();j++){
        for(int i =0;i<nums.size();i++){
            if(j == i) i+=1;
            if(nums[j]+nums[i] == target){
                result.push_back(j);
                 result.push_back(i);
                return result;
            }
            
        }
    }
    return result;
    }
};

//Add two numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* head = NULL;
         ListNode* temp = NULL;
         int carry = 0 ;
        while (l1 != NULL || l2 != NULL) {
            int sum = carry;
            
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
             cout<<sum<<endl;
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            cout<<sum<<endl;
            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
           
            if (temp == NULL) {
                temp = head = node;
            }
            
            else {
                temp->next = node;
                temp = temp->next;
            }
            cout<<sum<<endl;
        }
        
        if (carry > 0) {
            temp->next = new ListNode(carry);
        }
       

        return head;
    }
};

// Longest Substring Without Repeating Characters

public:
    int lengthOfLongestSubstring(string str) {
     int n = str.size();
    int res = 0;
 
    for (int i = 0; i < n; i++) {
         
        vector<bool> visited(256);
 
        for (int j = i; j < n; j++) {
 
           
            if (visited[str[j]] == true)
                break;
 
           
            else {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
 
        visited[str[i]] = false;
    }
    return res;
        }
    
};

//Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         nums2.insert(nums2.end(), nums1.begin(), nums1.end());
    sort (nums2.begin(), nums2.end());
    float median = 0;
    if(nums2.size()%2==0){
        median = ((float)nums2[nums2.size()/2-1] + (float)nums2[(nums2.size()/2)])/2;
    }
    else{
        median =nums2[nums2.size()/2];
    }
    cout<<"Median : "<<median<<endl;
    return median;
    }
};

//Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string str) {
   int n = str.size();

        bool table[n][n];
     
        memset(table, 0, sizeof(table));
        int maxLength = 1;
     
        for (int i = 0; i < n; ++i)
            table[i][i] = true;
        int start = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (str[i] == str[i + 1]) {
                table[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        for (int k = 3; k <= n; ++k) {

            for (int i = 0; i < n - k + 1; ++i) {

                int j = i + k - 1;
     
                if (table[i + 1][j - 1] && str[i] == str[j]) {
                    table[i][j] = true;
     
                    if (k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
     
    string nS;
    for (int i = start; i <= start + maxLength - 1; ++i)
        nS+= str[i];

    return nS;
    }
};

//ZigZag Conversion

class Solution {
public:
    string convert(string s, int nRows) {
       if (nRows <= 1)
                return s;

            const int len = (int)s.length();
            string *str = new string[nRows];

            int row = 0, step = 1;
            for (int i = 0; i < len; ++i)
            {
                str[row].push_back(s[i]);

                if (row == 0)
                    step = 1;
                else if (row == nRows - 1)
                    step = -1;

                row += step;
            }

            s.clear();
            for (int j = 0; j < nRows; ++j)
            {
                s.append(str[j]);
            }

            return s;
        
    }
};

//Reverse Integer



class Solution {
public:
    int reverse(int x) {
   int rev = 0;
        constexpr int top_limit = INT_MAX/10;
        constexpr int bottom_limit = INT_MIN/10;
        while (x) {
            if (rev > top_limit || rev < bottom_limit)
                return 0;
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};

//String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s) {
     if(s.length() == 0){
            return 0;
        }
        int i = 0;

        while(s[i] == ' '){
            i++;
        }

        bool isPositive = true;

        if(s[i] == '-' || s[i] == '+'){
            isPositive = (s[i] == '+' ? true : false);
            i++;
        }

        if(s[i] - '0' < 0 || s[i] - '0' > 9){
            return 0;
        }

        int num = 0;

        while(s[i] >= '0' && s[i] <= '9'){
            if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] - '0' > 7)){
                return isPositive ? INT_MAX : INT_MIN;
            }

            num = num*10 + (s[i] - '0');
            i++;
        }

        return isPositive ? num : num*-1;
    }
};


// Palindrome Number

int oneDigit(int num)
{

    return (num >= 0 && num < 10);
}

bool isPalUtil(int num, int* dupNum)
{
    
    if (oneDigit(num))
        return (num == (*dupNum) % 10);

    if (!isPalUtil(num / 10, dupNum))
        return false;

    *dupNum /= 10;

    return (num % 10 == (*dupNum) % 10);
}
class Solution {
public:
    bool isPalindrome(int num) {
     if (num < 0)
        return false;
    int* dupNum = new int(num);

    return isPalUtil(num, dupNum);
    }
};

// Regular Expression Matching

class Solution {
public:
    bool isMatch(string s, string p) {
 if (p.empty()) return s.empty();

    bool first_match = !s.empty() && (s[0] == p[0] || '.' == p[0]);
    if (p.size() >= 1 && '*' == p[1])
      return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
    else
      return  first_match && isMatch(s.substr(1), p.substr(1));

    }
};

//Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& A) {
  int len = A.size();
    int l = 0;
    int r = len -1;
    int area = 0;
     
    while (l < r)
    {
        
        area = max(area, min(A[l],
                        A[r]) * (r - l));
                         
            if (A[l] < A[r])
                l += 1;
                 
            else
                r -= 1;
    }
    return area;
    }
};

//Integer to Roman

class Solution {
public:
    string intToRoman(int num) {
         string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
       int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

       string result = "";

       for (auto int i = 0; i < 13; ++i)
       {
           while(num - values[i] >= 0)
           {
               result += str_romans[i];
               num -= values[i];
           }
       }

       return result;
    }
};

//Roman to Integer

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

class Solution {
public:
    int romanToInt(string str) {
         
    int res = 0;

    
    for (int i = 0; i < str.length(); i++)
    {
        
        int s1 = value(str[i]);

        if (i + 1 < str.length())
        {
           
            int s2 = value(str[i + 1]);

           
            if (s1 >= s2)
            {
                
                res = res + s1;
            }
            else
            {
    
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
    }
};

// Longest Common Prefix

string LCP(string X, string Y)
{
    int i = 0, j = 0;
    while (i < X.length() && j < Y.length())
    {
        if (X[i] != Y[j]) {
            break;
        }
 
        i++, j++;
    }
 
    return X.substr(0, i);
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& words) {
        string prefix = words[0];
    for (string s: words) {
        prefix = LCP(prefix, s);
    }
 
    return prefix;
    }
};

//3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
          vector<vector<int>> result;
        int i,low,high;
        if(nums.size()<3)
            return result;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size()-2;i++)
        {
            low=i+1;high=nums.size()-1;
            while(low<high)
            {
                if(i!=0 && nums[i]==nums[i-1])
                {
                    break;
                }
                else if((nums[low]+nums[high])==-nums[i])
                {
                    vector<int> triplet;
                    triplet.push_back(nums[low]);
                    triplet.push_back(nums[high]);
                    triplet.push_back(nums[i]);
                    result.push_back(triplet);
                    while(low<high && nums[low]==nums[low+1])
                        low++;
                    while(low<high && nums[high]==nums[high-1])
                        high--;
                    low++;high--;
                }
                else if((nums[low]+nums[high])>-nums[i])
                {
                    high--;
                }
                else if((nums[low]+nums[high])<-nums[i])
                {
                    low++;
                }
            }
        }
        return result;
    }
};

// 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int>& arr, int x) {
        long long closestSum = INT_MAX;
    for (int i = 0; i < arr.size() ; i++)
    {
        for(int j =i + 1; j < arr.size(); j++)
        {
            for(int k =j + 1; k < arr.size(); k++)
            {
                if(abs(x - closestSum) > abs(x - (arr[i] + arr[j] + arr[k])))
                    closestSum = (arr[i] + arr[j] + arr[k]);
            }
        }
    }
    return closestSum;
    }
};

//Letter Combinations of a Phone Number

unordered_map<char, string> L({{'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});
class Solution {
public:
    vector<string> letterCombinations(string D) {
          int len = D.size();
        vector<string> ans;
        if (!len) return ans;
        bfs(0, len, "", ans, D);
        return ans;
    }

    void bfs(int pos, int &len, string str, vector<string> &ans, string &D) {
        if (pos == len) ans.push_back(str);
        else {
            string letters = L[D[pos]];
            for (int i = 0; i < letters.size(); i++)
                bfs(pos+1, len, str+letters[i], ans, D);
        }
    }
    };

// 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        vector<vector<int>> res;
    if(a.size() < 4) return res;
    int n = a.size();
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int t2 = t-a[j]-a[i];
            int low = j+1, high = n-1;
            while(low<high){
                int sum = a[low] + a[high];
                if(sum == t2){
                    vector<int> temp(4,0);
                    temp[0] = a[i];
                    temp[1] = a[j];
                    temp[2] = a[low];
                    temp[3] = a[high];
                    res.push_back(temp);
                    while(low<high && a[low]== a[low+1]) low++;
                    while(low<high && a[high] == a[high-1]) high--;
                    low++;
                    high--;
                }
                else if(sum < t2) low++;
                else high--;
            }
            while(j+1 < n && a[j] == a[j+1]) j++;
        }
        while(i+1 < n && a[i] == a[i+1]) i++;
    }
    return res;
    }
};

//Remove Nth Node From End of List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int key) {
        ListNode *temp;
        ListNode *first = head;
        ListNode *second = head;
        for (int i = 0; i < key; i++)
        {

            if (second->next == NULL)
            {
                if (i == key - 1){
                    temp = head;
                    head = head->next;
                }
                return head;
            }
            second = second->next;
        }

        while (second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        temp = first->next;
        first->next = first->next->next;
        return head;
    }
};

// Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
      if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) st.push(s[i]);
      else
      {
        if (st.empty()) return false;
        if ((s[i] == ')') && (st.top() != '(')) return false;
        if ((s[i] == ']') && (st.top() != '[')) return false;
        if ((s[i] == '}') && (st.top() != '{')) return false;
        st.pop();
      }
    }
    return st.empty();
    }
};
