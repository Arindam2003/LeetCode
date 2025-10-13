class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int currSum=0;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            if(currSum>=0)
            { 
                maxSum=max(maxSum,currSum);
            }else{
                maxSum=max(maxSum,currSum);
                currSum=0;
            }
        }
        return maxSum;
    }
};