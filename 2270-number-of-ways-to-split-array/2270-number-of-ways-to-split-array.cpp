class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefix(nums.size(), 0);
        int i,j;
        if(nums.size()<2)
        {
            return 0;
        }
        prefix[0] = nums[0];
        for(i=1;i<nums.size();i++)
        {
            prefix[i]=nums[i]+prefix[i-1];
        }
        int count=0;
        for(i=0;i<prefix.size()-1;i++)
        {
            if(prefix[i]>=(prefix[prefix.size()-1]-prefix[i]))
            {
                count++;
            }
        }
        return count;
    }
};