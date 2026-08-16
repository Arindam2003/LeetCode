class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zc=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zc++;
            }
        }
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[j]=nums[i];
                j++;
            }
        }
        while(zc)
        {
            nums[j]=0;
            j++;
            zc--;
        }
        
    }
};