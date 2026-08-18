class Solution {
public:
	int partition(int st,int end,vector<int>&nums)
	{
		int p=nums[st];
		int l=st+1;
        int r=end;
		while(l<=r)
        {
            if(nums[l]<p && nums[r]>p)
            {
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
            if(nums[l]>=p)
            {
                l++;
            }
            if(nums[r]<=p)
            {
                r--;
            }
        }

        swap(nums[r],nums[st]);       

		return r;
	}


    int findKthLargest(vector<int>& nums, int k) {
    	int n=nums.size();
        int l=0,r=n-1;
        int pivot_idx;
        while(true)
        {
            pivot_idx=partition(l,r,nums);
            if(pivot_idx==k-1)
            {
                break;
            }
            else if(pivot_idx>k-1)
            {
                r=pivot_idx-1;
            }else {
                l=pivot_idx+1;
            }
        }
        return nums[pivot_idx];
    }
};