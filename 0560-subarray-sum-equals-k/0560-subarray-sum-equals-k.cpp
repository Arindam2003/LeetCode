class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(auto a:nums)
        {
            sum+=a;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};