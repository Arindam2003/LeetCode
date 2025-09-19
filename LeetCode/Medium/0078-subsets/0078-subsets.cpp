class Solution {
public:
    vector<vector<int>> subsetsHelper(vector<int>& nums,int i) {
        vector<vector<int>> ans;
        if(i==nums.size())
        {
            return {{}};
        }

        vector<vector<int>> partial=subsetsHelper(nums,i+1);
        // not take
        for(auto v: partial)
        {
            ans.push_back(v);
        }
        for(auto v: partial)
        {
            v.push_back(nums[i]);
            ans.push_back(v);
        }
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        return subsetsHelper(nums,0);
    }
};