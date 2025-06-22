class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n=nums.size();
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[cnt]=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};