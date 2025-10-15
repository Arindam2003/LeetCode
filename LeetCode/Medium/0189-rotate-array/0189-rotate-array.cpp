class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> temp1={};
        vector<int> temp2={};
        for(int i=0;i<nums.size()-k;i++)
        {
            temp1.push_back(nums[i]);
        }
        for(int i=nums.size()-k;i<nums.size();i++)
        {
            temp2.push_back(nums[i]);
        }
        
        for(int i=0;i<k;i++)
        {
            nums[i]=temp2[i];
        }
        for(int i=k;i<nums.size();i++)
        {
            nums[i]=temp1[i-k];
        }

    }
};