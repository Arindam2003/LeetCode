class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int normalSum = accumulate(nums.begin(), nums.end(), 0);
        int originalSum=0;
        for(int i=0;i<=nums.size();i++)
        {
            originalSum+=i;
        }
        return originalSum-normalSum;
    }
};