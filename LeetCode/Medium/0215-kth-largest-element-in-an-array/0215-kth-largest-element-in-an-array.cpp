class Solution {
public:
	int partition(int st,int end,vector<int>&nums)
	{
		int pivot=nums[end];
		int i=st;
		for(int j=st;j<=end-1;j++)
		{
			if(nums[j]<pivot)
			{
				swap(nums[i],nums[j]);
				i++; 
			}
		}
        swap(nums[i],nums[end]); // Quick Sort..... upto this
		return i;
	}

	int QuickSelect(int st,int end,int kth,vector<int>&nums)
	{
        // bse case
		if(st==end)
		{
			return nums[st];
		}

        // recursive case
		int ans=partition(st,end,nums);

		if(ans==kth)
		{
			return nums[ans];
		}
        else if (ans<kth) // i need to go right side
		{ 
			return QuickSelect(ans+1,end,kth,nums);
		}
        else // i need to go left side
		{
			return QuickSelect(st,ans-1,kth,nums);
		}
	}

    int findKthLargest(vector<int>& nums, int k) {
    	int n=nums.size();
    	int index=n-k;
        return QuickSelect(0,n-1,index,nums);
    }
};