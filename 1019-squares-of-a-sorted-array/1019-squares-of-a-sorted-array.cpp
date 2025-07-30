class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]*nums[i]);
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
};