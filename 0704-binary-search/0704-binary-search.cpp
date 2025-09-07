class Solution {
    int binarySearch(vector<int>&nums,int left,int right,int target)
    {
        if(left==right)
        {
            return -1;
        }
        int mid=(left+right)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        bool isGreater= target>nums[mid]?true:false;
        if(isGreater)
        {
            return binarySearch(nums,mid+1,right,target);
        }
        else{
            return binarySearch(nums,left,mid,target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size();
        sort(nums.begin(),nums.end());
        return binarySearch(nums,l,r,target);
    }
};