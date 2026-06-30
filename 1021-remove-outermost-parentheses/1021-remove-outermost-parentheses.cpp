class Solution {
public:
    string removeOuterParentheses(string s) {
        int level=0;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                level++;
                if(level>1)
                {
                    ans+='(';
                }
            }else{
                if(level>1)
                {
                    ans+=')';
                }
                level--;
            }
        }

        return ans;
    }
};