class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n=nums.size();
        int alic=INT_MAX;
        int bob=INT_MAX;
        vector<int>ans;
        while(!nums.empty())
        {
            auto it=min_element(nums.begin(),nums.end());
            if(alic==INT_MAX)
            {
                alic=*it;
                nums.erase(it);
            }else if(bob==INT_MAX)
            {
                bob=*it;
                nums.erase(it);
            }

            if(alic!=INT_MAX && bob!=INT_MAX)
            {
                ans.push_back(bob);
                bob=INT_MAX;
                ans.push_back(alic);
                alic=INT_MAX;
            }
        }
        return ans;
    }
};