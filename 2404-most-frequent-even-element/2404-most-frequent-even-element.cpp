class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> m;
        for(auto a:nums)
        {
            if(a%2==0)
            {
                m[a]++;
            }
        }
        int ans=-1,most=0;
        for(auto it:m)
        {
            if(it.second>most)
            {
                most=it.second;
                ans=it.first;
            }
        }

        return ans;
    }
};