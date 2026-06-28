class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>>result;

        for(int i=0;i<n;i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(strs[i]);
        }

        for(auto a:mpp)
        {
            result.push_back(a.second);
        }

        return result;
    }
};