class Solution {
public:
    string backspace(string x)
    {
        stack<char> st;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='#')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(x[i]);
            }
        }
        string s="";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }   
        return s;
    }
    bool backspaceCompare(string s, string t) {
        string A=backspace(s);
        string B=backspace(t);
        if(A.length()!=B.length())
        {
            return false;
        }else{
            for(int i=0;i<A.length();i++)
            {
                if(A[i]!=B[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
};