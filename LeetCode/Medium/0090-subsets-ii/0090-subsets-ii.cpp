class Solution {
public:
    vector<vector<int>> result = {};
    void helper(vector<int>& nums, int st, vector<int>& current) {
        result.push_back(current);
        for (int i = st; i < nums.size(); i++) {
            if (i > st && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]);
            helper(nums, i + 1, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current = {};
        helper(nums, 0, current);
        return result;
    }
};