class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        long long sum = 0;
        int prev = 0;

        for(int num : nums)
        {
            // Ignore duplicates
            if(num == prev)
                continue;

            int gap = num - prev - 1;

            if(gap >= k)
            {
                int first = prev + 1;
                int last = prev + k;

                sum += 1LL * k * (first + last) / 2;

                return sum;
            }

            // Take all numbers in this gap
            sum += 1LL * gap * (prev + num) / 2;

            k -= gap;
            prev = num;
        }

        // If we still need numbers,
        // take them after the last element.
        int first = prev + 1;
        int last = prev + k;

        sum += 1LL * k * (first + last) / 2;

        return sum;
    }
};