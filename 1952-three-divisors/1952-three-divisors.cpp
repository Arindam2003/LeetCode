class Solution {
public:
    vector<bool>isPrime(int n)
    {
        vector<bool> ans(n+1, true);
        ans[0]=ans[1]=false;

        for(int i=2;i<=n;i++)
        {
            if(!ans[i] || 1LL*i*i>n) // true..
            {
                continue;
            }
            for(int j=i*i;j<=n;j+=i)
            {
                
                ans[j]=false;
            }
        }
        return ans;
    }

    bool isThree(int n) {
        vector<bool> isPrim=isPrime(n);
        int sqn=round(sqrt(n));

        return (sqn*sqn==n && isPrim[sqn]);
    }
};