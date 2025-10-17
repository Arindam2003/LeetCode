class Solution {
public:
    bool ispalindrome(string s,int st,int end)
    {
        while(st<=end)
        {
            if(s[st]!=s[end])
            {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st=0;
        int end=s.length()-1;
        while(st<=end)
        {
            if(s[st]!=s[end])
            {
                if(ispalindrome(s,st+1,end) || ispalindrome(s,st,end-1))
                {
                    return true;
                }else{
                    return false;
                }
            }
            st++;
            end--;
        }
        return true;
    }
};