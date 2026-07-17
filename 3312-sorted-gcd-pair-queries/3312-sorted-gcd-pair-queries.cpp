class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
         int mx = *max_element(nums.begin(), nums.end());

        // Frequency of each value
        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // exact[d] = pairs whose gcd is exactly d
        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {

            long long pairs = cnt[d] * (cnt[d] - 1) / 2;

            exact[d] = pairs;

            for (int multiple = d + d; multiple <= mx; multiple += d) {
                exact[d] -= exact[multiple];
            }
        }

        // prefix[i] = number of pairs having gcd <= i
        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int> ans;

        for (long long q : queries) {

            // q is 0-indexed
            int g = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    
    }
};