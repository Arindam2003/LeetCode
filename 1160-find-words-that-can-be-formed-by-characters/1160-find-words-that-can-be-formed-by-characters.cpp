class Solution {
public:
    bool isGood(string s,unordered_map<char,int>mp){
        unordered_map<char,int> map;
        for(auto a: s)
        {
            map[a]++;
        }

        for(auto a:map)
        {
            if(mp[a.first]>=a.second)
            {
                mp[a.first]-=a.second;
            }else{
                return false;
            }
        }
        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;

        for(auto a: chars)
        {
            mp[a]++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            if(isGood(words[i],mp))
            {
                ans+=words[i].size();
            }
        }

        return ans;

    }
};