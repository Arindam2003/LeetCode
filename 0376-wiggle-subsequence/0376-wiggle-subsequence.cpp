class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        int last_diff=0;//1--pos. 0--neg.
        int ans=1;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]>0 && last_diff<=0)
            {
                ans++;
                last_diff=1;
            }else if(nums[i]-nums[i-1]<0 && last_diff>=0)
            {
                ans++;
                last_diff=-1;
            }
        }
        return ans;
    }
};