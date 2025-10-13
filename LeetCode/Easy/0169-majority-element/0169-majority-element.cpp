class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;

        for(int n:nums)
        {
            mpp[n]++;
        }

        int max=INT_MIN;
        int maxElem;
        for(auto &p:mpp)
        {
            if(p.second>max)
            {
                maxElem=p.first;
            }
        }
        return maxElem;
    }
};