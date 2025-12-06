class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> newNums=nums;

        sort(newNums.begin(), newNums.end());
        int n = nums.size();
        int s=-1,e=-2;
        for (int i = 0; i < n; i++) {
            if (nums[i] != newNums[i]) {
                if(s==-1)
                {
                    s=i;
                }else{
                    e=i;
                }
            }
        }
        return e-s+1;
    }
};