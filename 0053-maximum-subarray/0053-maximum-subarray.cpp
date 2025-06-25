class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxSum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxSum;
    }
};