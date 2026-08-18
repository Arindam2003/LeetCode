class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Find median using nth_element
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;

        // Virtual indexing
        auto index = [n](int i) {
            return (1 + 2 * i) % (n | 1);
        };

        int left = 0;
        int i = 0;
        int right = n - 1;

        // 3-way partition
        while (i <= right) {

            if (nums[index(i)] > median) {
                swap(nums[index(left)], nums[index(i)]);
                left++;
                i++;
            }

            else if (nums[index(i)] < median) {
                swap(nums[index(i)], nums[index(right)]);
                right--;
            }

            else {
                i++;
            }
        }
    }
};