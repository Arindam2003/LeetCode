class Solution {
public:
    int firstOccurence(vector<int>&nums,int target)
    {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if (nums[mid] == target) {
                ans = mid;
                right = mid - 1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }

    int lastOccurence(vector<int>&nums,int target)
    {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int ans=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first=firstOccurence(nums,target);
        int last=lastOccurence(nums,target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};