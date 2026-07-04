class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;


        for(int i=0;i<p.size();i++)
        {
            mp1[p[i]]++;
        }

        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            mp2[s[i]]++;
            if(i>=p.size())
            {
                mp2[s[i-p.size()]]--;
                if(mp2[s[i-p.size()]]==0)
                {
                    mp2.erase(s[i-p.size()]);
                }
            }

            if(mp1==mp2)
            {
                ans.push_back(i-p.size()+1);
            }
        }

        return ans;

    }
};