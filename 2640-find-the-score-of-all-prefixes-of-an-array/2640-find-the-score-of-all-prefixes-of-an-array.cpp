class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> conver;

        vector<long long> prefixMax;
        prefixMax.push_back(nums[0]);
        int max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(max>nums[i])
            {
                prefixMax.push_back(max);
            }
            else{
                prefixMax.push_back(nums[i]);
                max=nums[i];
            }
        }
        conver.push_back(nums[0] + prefixMax[0]);
        for(int i=1;i<nums.size();i++)
        {
            conver.push_back(nums[i] + prefixMax[i]);
        }

        vector<long long> ans;
        long long temp=0;
        for(int i=0;i<conver.size();i++)
        {
            temp=temp+conver[i];
            ans.push_back(temp);
        }
        return ans;
    }
};