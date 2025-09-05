class Solution {
    bool isArithmetic(vector<int> &nums)
    {
        int n=nums.size();
        if(n<2)
        {
            return false;
        }
        if(n==2)
        {
            return true;
        }
        int i=0;
        int j=1;
        int target=nums[j]-nums[i];
        while(j<n-1)
        {
            i++;
            j++;
            if(nums[j]-nums[i]!=target)
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool> ans;
        for(int i=0;i<m;i++)
        {
            vector<int> subarr(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(subarr.begin(),subarr.end());
            isArithmetic(subarr)?ans.push_back(true):ans.push_back(false);
        }
        return ans;
    }
};