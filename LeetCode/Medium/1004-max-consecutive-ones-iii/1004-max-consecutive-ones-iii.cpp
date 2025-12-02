class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        int maxNum=0;
        int zeroCount=0;
        while(r<n && l<n)
        {
            if(nums[r]==0)
            {
                zeroCount++;
            }
            while(zeroCount>k)
            {
                if(nums[l]==0)
                {
                    zeroCount--;
                }
                l++;
            }
            int maxLen=r-l+1;
            maxNum=max(maxLen,maxNum);
            r++;
        }
        return maxNum;
    }
};