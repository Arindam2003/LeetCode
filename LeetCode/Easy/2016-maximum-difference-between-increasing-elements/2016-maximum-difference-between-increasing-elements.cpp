class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int min_value=nums[0];
        for(int j=1;j<nums.size();j++)
        {
            if(nums[j]>min_value)
            {
                ans=max(ans,nums[j]-min_value);
            }
            min_value=min(min_value,nums[j]);
        }
        return ans;
    }
};