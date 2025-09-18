class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                temp+=s[i];
            }
        }
        transform(temp.begin(),temp.end(),temp.begin(), :: tolower);
        int left=0;
        int right=temp.size()-1;
        while(left<=right)
        {
            if(temp[left]!=temp[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};