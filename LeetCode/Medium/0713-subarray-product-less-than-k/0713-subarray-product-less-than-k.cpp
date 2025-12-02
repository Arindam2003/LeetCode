class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int prod=1;
        int count=0;
        while(r<n)
        {
            prod=prod*nums[r];
            while(prod>=k && l<=r)
            {
                prod=prod/nums[l];
                l++;
            }
            count=count+(r-l+1);
            r++;
        }
        return count;
    }
};