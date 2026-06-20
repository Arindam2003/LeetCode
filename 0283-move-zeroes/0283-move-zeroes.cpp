class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=-1;
        for(int j=0;j<n;j++)
        {
            if(nums[j]!=0)
            {
                i++;
                nums[i]=nums[j];
            }
        }
        while(i<n-1)
        {
            i++;
            nums[i]=0;
        }
    }
};