class Solution {
public:
    string removeOuterParentheses(string s) {
        int i;
        int counter=0;
        string ans="";
        for(i=0;s[i];i++)
        {
            if(s[i]=='(')
            {
                if (counter>0)
                {
                    ans=ans+'(';
                }
                counter++;
            }
            if(s[i]==')')
            {
                counter--;
                if(counter>0)
                {
                    ans=ans+')';
                }
            }
        }
        return ans;
    }
};