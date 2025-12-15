class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long totalSum = prefix[n - 1];
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            long long left =
                (long long)nums[i] * i - (i > 0 ? prefix[i - 1] : 0);
            long long right =
                (totalSum - prefix[i]) - (long long)nums[i] * (n - i - 1);
            ans[i] = left + right;
        }

        return ans;
    }
};