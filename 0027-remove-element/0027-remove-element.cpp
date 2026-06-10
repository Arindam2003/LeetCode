class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int count_val=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=val)
            {
                nums[count_val]=nums[i];
                count_val++;
            }
        }
        
        return count_val;
    }
};