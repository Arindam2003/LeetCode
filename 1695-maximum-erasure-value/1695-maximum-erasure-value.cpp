class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=0;
        while(j<n)
        {
            if(mp[nums[j]])
            {   
                while(mp[nums[j]])
                {
                    mp[nums[i]]--;
                    i++;
                }
            }
            mp[nums[j]]++;
            ans=max(ans,accumulate(nums.begin() + i, nums.begin() + j + 1, 0));
            j++;
        }
        return ans;
    }
};