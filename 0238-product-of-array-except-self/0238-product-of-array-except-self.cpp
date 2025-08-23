class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProd;
        prefixProd.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            prefixProd.push_back(prefixProd[i-1]*nums[i]);
        }
        int n=nums.size();
        vector<int> sufixProd(n,0);
        sufixProd[n-1]=nums[n-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            sufixProd[i]=sufixProd[i+1]*nums[i];
        }
        vector<int> ans;
        ans.push_back(sufixProd[1]);
        for(int i=1;i<n-1;i++)
        {
            ans.push_back(prefixProd[i-1]*sufixProd[i+1]);
        }
        ans.push_back(prefixProd[n-2]);
        return ans;
    }
};