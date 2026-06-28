class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0;
        int ans=0;
        for(auto i:s)
        {
            if(i=='R')
            {
                count++;
            }else if(i=='L')
            {
                count--;
            }

            if(count==0)
            {
                ans++;
            }
        }
        return ans;
    }
};