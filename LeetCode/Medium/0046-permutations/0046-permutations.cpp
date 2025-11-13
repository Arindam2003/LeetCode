class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int> &nums,vector<int>&temp)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end())
            {
                continue;
            }
            temp.push_back(nums[i]);
            backtrack(nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        backtrack(nums,temp);
        return ans;
    }
};