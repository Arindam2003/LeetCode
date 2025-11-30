class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current = 0;
        for (int i = 0; i < k; i++) {
            current += nums[i];
        }

        double ans = current / k;
        for (int st = 1, en = k; en < nums.size(); st++, en++) {
            current -= nums[st - 1];
            current += nums[en];
            double temp= current / k;
            ans = max(temp, ans);
        }
        return ans;
    }
};