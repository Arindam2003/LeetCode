class Solution {
public:
    int maxnum(vector<int>&piles)
    {
        int maxnum=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            if(maxnum<piles[i])
            {
                maxnum=piles[i];
            }
        }
        return maxnum;
    }
    long long totalmal(vector<int>&piles,int tr)
    {
        long long totalmal=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%tr==0)
            {
                totalmal=totalmal+(piles[i]/tr);
            }
            else{
                totalmal=totalmal+((piles[i]/tr)+1);
            }
        }
        return totalmal;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maxnum(piles);
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long totalh=totalmal(piles,mid);
            if(totalh<=h)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};