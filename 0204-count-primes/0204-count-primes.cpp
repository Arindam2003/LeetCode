class Solution {
public:
    vector<bool> primeSieve(int n)
    {
        vector<bool> isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false;

        for(int i=2;i<=n;i++)
        {
            if(!isPrime[i] || (long long)i*i>(long long)n)
                continue;
            for(int j=i*i;j<=n;j+=i)
            {
                isPrime[j]=false;
            }
        }
        return isPrime;
    }
    int countPrimes(int n) {
        if(n==0)
        {
            return 0;
        }
        vector<bool>p=primeSieve(n);
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(p[i]==true)
            {
                ans++;
            }
        }
        return ans;
    }
};