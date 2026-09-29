
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate second elements
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[left]
                                  + nums[right];

                    if (sum == target) {
                        ans.push_back({
                            nums[i], nums[j],
                            nums[left], nums[right]
                        });

                        left++;
                        right--;

                        // Skip duplicate third elements
                        while (left < right &&
                               nums[left] == nums[left - 1])
                            left++;

                        // Skip duplicate fourth elements
                        while (left < right &&
                               nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};