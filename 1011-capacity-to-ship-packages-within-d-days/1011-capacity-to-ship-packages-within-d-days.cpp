class Solution {
    int check(vector<int>& weights, int OneDay) {
        int count = 1;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > OneDay) {
                count++;
                sum = 0;
            }
            sum += weights[i];
        }
        return count;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int neededDays = check(weights, mid);
            if (neededDays <= days) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }

        return ans;
    }
};