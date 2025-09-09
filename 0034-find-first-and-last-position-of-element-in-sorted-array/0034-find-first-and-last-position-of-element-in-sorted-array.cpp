class Solution {
public:
    int firstOccur(vector<int>& nums, int target) {

        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end()|| *it != target) {
            return -1;
        }
        return (it - nums.begin());
    }
    int LastOccur(vector<int>& nums, int target) {
        auto it = upper_bound(nums.begin(), nums.end(), target);
        if (it == nums.begin()) {
            return -1;
        }
        --it;
        if (*it != target) {
            return -1;
        }
        return (it - nums.begin());
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccur(nums, target);
        int last = LastOccur(nums, target);

        return {first, last};
    }
};