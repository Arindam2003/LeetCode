class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=1;i<n;i++){
            if(nums[j]==0 && nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};