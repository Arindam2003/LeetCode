class Solution {
public:

int lastO(vector<int> &nums,int target)
    {   
        int index=-1;
        int n=nums.size();
        int st=0,end=n-1;
        while(st<=end)
        {
            int mid=(st+end)/2;
            if(nums[mid]==target)
            {
                index=mid;
                st=mid+1;
            }else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return index;
    }

    int firstO(vector<int> &nums,int target)
    {   
        int index=-1;
        int n=nums.size();
        int st=0,end=n-1;
        while(st<=end)
        {
            int mid=(st+end)/2;
            if(nums[mid]==target)
            {
                index=mid;
                end=mid-1;
            }else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={};
        int first=firstO(nums,target);
        int last=lastO(nums,target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};  