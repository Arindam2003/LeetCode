class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        unordered_map<int,int>mpp;

        for(int i=0;i<n;i++)
        {
            int number=numbers[i];
            int more=target-number;
            if(mpp.find(more)!=mpp.end())
            {
                return {mpp[more]+1,i+1};
            }
            mpp[number]=i;
        }
        return {-1,-1};
    }
};