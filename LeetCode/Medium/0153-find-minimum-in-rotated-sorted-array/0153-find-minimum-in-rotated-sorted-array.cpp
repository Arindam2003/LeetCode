class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=n-1;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if (nums[(mid-1+n)%n]> nums[mid] && nums[mid]<nums[(mid+1)%n])
            {
                return nums[mid];
            }else if(nums[st]<=nums[mid] && nums[mid]<=nums[end]) //Full sorted array
            {
                return nums[st];
            }
            else if(nums[st]<=nums[mid]) //Left Sorted
            {
                st=mid+1;
            }else //Right sorted
            {
                end=mid-1;
            }
        }
        return -1;
    }
};