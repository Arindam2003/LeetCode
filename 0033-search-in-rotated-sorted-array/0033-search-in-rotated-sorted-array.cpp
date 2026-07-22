class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0,end=n-1;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[st]<=nums[mid]) // Left sorted
            {
                if(target>=nums[st] && target<=nums[mid])
                {
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }
            else // right sorted
            {
                if(target>=nums[mid] && target<=nums[end])
                {
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};