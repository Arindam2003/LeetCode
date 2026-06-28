class Solution {
public:
    bool palindrome(string s)
    {
        int f=0;
        int l=s.size()-1;
        while(f<=l)
        {   
            if(s[f]!=s[l])
            {
                return false;
            }
            f++;
            l--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        string result="";
        for(char &c:s)
        {
            if(isalnum(c))
            {
                result+=c;
            }
        }
        transform(result.begin(),result.end(),result.begin(),::tolower);
        return palindrome(result);
    }
};