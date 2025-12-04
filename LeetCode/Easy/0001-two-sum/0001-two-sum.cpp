class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int number=nums[i];
            int more=target-number;
            if(mpp.find(more)!=mpp.end())
            {
                return {i,mpp[more]};
            }
            mpp[number]=i;
        }
        return {-1, -1};
    }
};