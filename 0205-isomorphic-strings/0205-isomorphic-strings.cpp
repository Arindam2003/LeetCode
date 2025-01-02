class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char, vector<int>> mp1;
        unordered_map<char, vector<int>> mp2;
        for(int i=0;i<s.size();i++)
        {
            mp1[s[i]].push_back(i);
        }
        for(int i=0;i<t.size();i++)
        {
            mp2[t[i]].push_back(i);
        }
        for(int i=0;i<s.size();i++)
        {
            if(mp1[s[i]]!=mp2[t[i]])
            return false;
        }
        return true;
    }
};