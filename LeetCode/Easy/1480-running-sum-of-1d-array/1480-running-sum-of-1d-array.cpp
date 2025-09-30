class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int temp=nums[0];
        ans.push_back(temp);
        for(int i=1;i<nums.size();i++)
        {
            temp+=nums[i];
            ans.push_back(temp);
        }
        return ans;
    }
};