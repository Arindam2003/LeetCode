class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int lm=0;
        for(int n:nums)
        {
            if(n==1)
            {
                lm++;
                ans=max(ans,lm);
            }
            else if(n==0)
            {
                lm=0;
            }
        }
        return ans;
    }
};