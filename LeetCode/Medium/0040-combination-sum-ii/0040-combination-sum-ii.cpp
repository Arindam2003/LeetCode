class Solution {
public:
    vector<vector<int>> result = {};
    void helper(int st, int target, vector<int>& candidates,
                vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
        }
        for (int i = st; i < candidates.size(); i++) {
            if (i > st && candidates[i] == candidates[i - 1])
                continue;
            if (target < candidates[i])
                break;
            if (target >= candidates[i]) {
                current.push_back(candidates[i]);
                helper(i + 1, target - candidates[i], candidates, current);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current = {};
        helper(0, target, candidates, current);
        return result;
    }
};