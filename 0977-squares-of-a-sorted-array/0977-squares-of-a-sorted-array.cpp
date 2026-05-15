class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        
        int st=0;
        int end=n-1;
        int idx=n-1;
        while(st<=end)
        {
            if(nums[st]*nums[st] > nums[end]*nums[end])
            {
                temp[idx]=nums[st]*nums[st];
                st++;
            }else{
                temp[idx]=nums[end]*nums[end];
                end--;
            }
            idx--;
        }
        return temp;
    }
};