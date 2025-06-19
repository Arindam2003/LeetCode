class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minval=nums[0];
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-minval>k){
                count++;
                minval=nums[i];
            }
        }
        return count;
    }
};