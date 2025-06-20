class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> numsForLeft(n, 0);
        vector<int> numsForRight(n, 0);
        if (n == 1) {
            return numsForLeft;
        }
        for (int i = 1; i < n; i++) {
            numsForLeft[i]=numsForLeft[i-1] + nums[i-1];
        }
        for (int i = n - 2; i >= 0; i--) {
            numsForRight[i]=numsForRight[i+1] + nums[i+1];
        }

        vector<int> ans(n,0);
        for (int i = 0; i < n; i++) {
            int diff = numsForLeft[i] - numsForRight[i];
            ans[i]=abs(diff);
        }
        return ans;
    }
};