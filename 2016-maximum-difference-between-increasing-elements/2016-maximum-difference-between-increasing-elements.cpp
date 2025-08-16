class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1, min_till_now=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]>min_till_now)
            {
                ans=max(ans,nums[i]-min_till_now);
            }
            min_till_now=min(nums[i],min_till_now);
        }
        return ans;
    }
};