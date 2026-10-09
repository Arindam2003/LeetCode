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

    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>prime=primeSieve(n);
        vector<vector<int>> ans;
        for(int i=2;i<=n/2;i++)
        {
            if(prime[i]==true && prime[n-i]==true)
            {
                ans.push_back({i,n-i});
            }
        }

        return ans;
    }
};