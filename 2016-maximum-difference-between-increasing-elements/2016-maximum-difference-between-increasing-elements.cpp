class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();

        int minEle=nums[0];
        int maxDiff=-1;
        for(int j=1;j<n;j++)
        {
            if(minEle<nums[j])
            {
                maxDiff=max(nums[j]-minEle,maxDiff);
            }
            else{
                minEle=nums[j];
            }
        }
        return maxDiff;
    }
};