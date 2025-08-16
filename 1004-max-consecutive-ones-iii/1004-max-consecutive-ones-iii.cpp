class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int kval=0;
        int len=0;
        int ans=0;
        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
            {
                kval++;
            }
            while(kval>k)
            {
                if(nums[l]==0)
                {
                    kval--;
                }
                l++;
            }
            len=r-l+1;
            ans=max(ans,len);
        }
        return ans;
    }
};