class Solution {
    void recur(int i,vector<int> &arr, vector<int> &nums,int n, vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            ans.push_back(arr);
            return;
        }
        recur(i+1,arr,nums,n,ans);
        arr.push_back(nums[i]);
        recur(i+1,arr,nums,n,ans);
        arr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        int n=nums.size();
        recur(0,arr,nums,n,ans);
        return ans;
    }
};