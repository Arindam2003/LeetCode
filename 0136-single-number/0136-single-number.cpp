class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0 ;
        for(int i=0;i<nums.size();i++)
        {
            xr=xr^nums[i];
        }
        return xr;
    }
};