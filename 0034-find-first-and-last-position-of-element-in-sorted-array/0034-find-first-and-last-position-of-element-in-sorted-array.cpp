class Solution {
public:
    int firstOccur(vector<int>&nums, int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int f=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                f=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return f;
    }
    int LastOccur(vector<int>&nums, int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int l=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                l=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOccur(nums,target);
        int last=LastOccur(nums,target);
        return {first,last};
    }
};