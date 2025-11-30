class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixArr(n,0);
        prefixArr[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            prefixArr[i]=nums[i]+prefixArr[i-1];
        }
        return prefixArr;
    }
};