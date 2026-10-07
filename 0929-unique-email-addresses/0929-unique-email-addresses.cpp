class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;

        for (auto e : emails) {
            bool atTheRateFound = false;
            bool plusFound=false;
            string s = "";
            
            for( int i=0;i<e.size();i++)
            {
                char a = e[i];
                if(a=='@')
                {
                    atTheRateFound=true;
                    s+=a;
                }else if(a=='+')
                {
                    if(atTheRateFound)
                    {
                        s+=a;
                    }else{
                        plusFound=true;
                    }
                }else if(a=='.')
                {
                    if(atTheRateFound)
                    {
                        s+=a;
                    }else{
                        continue;
                    }
                }else{
                    if(plusFound && !atTheRateFound)
                    {
                        continue;
                    }
                    s+=a;
                }
            }
            st.insert(s);
        }
        int ans = st.size();
        return ans;
    }
};