class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        int unique=0;
        while(i<n)
        {
            nums[unique]=nums[i];
            while(j<n && nums[i]==nums[j])
            {
                j++;
            }
            unique++;
            i=j;
        }
        return unique;
    }
};