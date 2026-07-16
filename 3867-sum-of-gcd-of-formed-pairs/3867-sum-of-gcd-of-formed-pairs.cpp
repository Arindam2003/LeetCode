class Solution {
public:
    long long gcd(long long a,long long b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixMax(n,0);
        prefixMax[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefixMax[i]=max(prefixMax[i-1],nums[i]);
        }

        vector<int> prefGcd;
        for(int i=0;i<n;i++)
        {
            prefGcd.push_back(gcd(prefixMax[i],nums[i]));
        }


        sort(prefGcd.begin(),prefGcd.end());

        long long ans=0;
        int i=0,j=prefGcd.size()-1;
        while(i<j)
        {
            ans+=gcd(prefGcd[i],prefGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};