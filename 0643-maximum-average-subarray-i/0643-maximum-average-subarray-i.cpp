class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int max=0;
        for(int i=0;i<k;i++)
        {
            sum=sum+nums[i];
        }
        max=sum;
        for(int i=1;i<n-k+1;i++)
        {
            sum=sum-nums[i-1]+nums[i+k-1];
            if(sum>max)
            {
                max=sum;
            }
        }

        double result=(double)max/k;
        return result;
    }
};