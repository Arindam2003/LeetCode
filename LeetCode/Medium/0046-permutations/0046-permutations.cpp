class Solution {
public:
    vector<vector<int>>ans;
    void permuteHelper(vector<int> &nums,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            permuteHelper(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelper(nums,0);
        return ans;
    }
};