class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int &n:nums)
        {
            mpp[n]++;
        }

        int max_freq=0;
        
        for(auto &m:mpp)
        {
            max_freq=max(max_freq,m.second);
        }

        int ans=0;

        for(auto &m: mpp)
        {
            if(m.second==max_freq)
            {
                ans+=m.second;
            }
        }
        return ans;
    }
};