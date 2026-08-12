class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int normalSum = accumulate(nums.begin(), nums.end(), 0);
        int originalSum=(n*(n+1))/2;

        return originalSum-normalSum;
    }
};