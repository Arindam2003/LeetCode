class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        for(auto a: mpp)
        {
            if(a.second==1)
            {
                return a.first;
            }
        }

        return nums[0];
    }
};