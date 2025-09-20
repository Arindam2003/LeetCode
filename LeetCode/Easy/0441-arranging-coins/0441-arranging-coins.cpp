class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            long long temp=(1LL * i*(i+1))/2;
            if(temp>n)
            {
                return ans;
            }
            ans=i;
        }
        return ans;
    }
};