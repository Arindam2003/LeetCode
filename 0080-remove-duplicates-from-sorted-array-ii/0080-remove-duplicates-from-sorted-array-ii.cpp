class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        if(n<2)
            return n;

        int k=0;
        int c=1;
        nums[k++]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                c++;
            }else{  
                c=1;
            }

            if(c<=2)
            {
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};