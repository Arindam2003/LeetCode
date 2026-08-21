class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int max_elem=0;
        for(int i=0;i<nums.size();i++)
        {
            max_elem=max(max_elem,nums[i]);
            mpp[nums[i]]++;
        }
        for(int i=1;i<=max_elem;i++)
        {
            if(mpp.find(i)==mpp.end())
            {
                return i;
            }
        }
    

        return max_elem+1;
    }
};