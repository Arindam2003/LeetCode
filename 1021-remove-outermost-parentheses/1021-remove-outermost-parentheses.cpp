class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                if(st.size()>1)
                {
                    ans+='(';
                }
            }else{
                if(st.size()>1)
                {
                    ans+=')';
                }
                st.pop();
            }
        }

        return ans;
    }
};