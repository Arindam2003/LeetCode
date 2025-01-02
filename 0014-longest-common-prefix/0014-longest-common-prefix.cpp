class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
        return ""; 
        }
        string ans="";
        sort(strs.begin(),strs.end());
        int i=0;
        string first=strs[0];
        string last=strs[(strs.size())-1];
        for(i=0;i<first.size();i++)
        {
            if(first[i]!=last[i])
            {
                break;
            }
            ans=ans+first[i];
        }
        return ans;
    }
};