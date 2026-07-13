class Solution {
public:
    int digitCount(int n) {
        if (n == 0) return 1;

        int cnt = 0;
        while (n) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int lowDigits = digitCount(low);
        int highDigits = digitCount(high);

        for (int len = lowDigits; len <= highDigits; len++) {

            // Starting digit can be at most (10 - len)
            for (int start = 1; start <= 10 - len; start++) {

                int num = 0;

                // Build the sequential number
                for (int d = start; d < start + len; d++) {
                    num = num * 10 + d;
                }

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};