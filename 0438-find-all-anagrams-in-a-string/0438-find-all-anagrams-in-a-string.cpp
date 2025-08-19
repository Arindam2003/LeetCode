class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pCount(26,0);
        vector<int> sCount(26,0);
        vector<int> ans;
        for(int i=0;i<p.size();i++)
        {
            pCount[p[i]-'a']++;
        }

        for(int i=0;i<s.size();i++)
        {
            sCount[s[i]-'a']++;

            if(i>=p.size())
            {
                sCount[s[i-p.size()]-'a']--;
            }

            if(sCount==pCount)
            {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};