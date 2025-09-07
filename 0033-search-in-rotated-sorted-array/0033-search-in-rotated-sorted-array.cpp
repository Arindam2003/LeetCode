class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int lastElem = nums[right];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target > lastElem && nums[mid] <= lastElem) {
                right = mid - 1;
            } else if (target <= lastElem && nums[mid] > lastElem) {
                left = mid + 1;
            } else {
                if (target == nums[mid]) {
                    return mid;
                } else if (target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};