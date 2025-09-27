class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int max_cnt=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                cnt++;
                max_cnt=max(max_cnt,cnt);
            }else if(nums[i]==0)
            {
                max_cnt=max(max_cnt,cnt);
                cnt=0;
            }
        }
        return max_cnt;
    }
};