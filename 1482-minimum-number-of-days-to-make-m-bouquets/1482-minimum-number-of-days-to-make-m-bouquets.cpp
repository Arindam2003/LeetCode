class Solution {
public:
    bool possible(vector<int>& nums, int day, int m, int k) {
        int n = nums.size();
        int count = 0;
        int noOfB = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= day) {
                count++;
            } else {
                noOfB = noOfB + (count / k);
                count = 0;
            }
        }
        noOfB = noOfB + (count / k);
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n =bloomDay.size();
        if (val > n)
            return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini, high = maxi, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};