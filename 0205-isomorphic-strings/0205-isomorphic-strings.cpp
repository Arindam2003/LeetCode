class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smpp;
        unordered_map<char,char> tmpp;

        for(int i=0;i<s.size();i++)
        {
            if(smpp.find(s[i])!=smpp.end() && smpp[s[i]]!=t[i]) // find
            {
                    return false;
            }
            if(tmpp.find(t[i])!=tmpp.end() && tmpp[t[i]]!=s[i]) // find
            {
                    return false;
            }
            smpp[s[i]]=t[i];
            tmpp[t[i]]=s[i];
        }
        return true;

    }
};