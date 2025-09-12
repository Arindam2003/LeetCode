class Solution {
public:
    long reqHour(vector<int>piles,long speed)
    {
        int n=piles.size();
        long hour=0;
        for(int i=0;i<n;i++)
        {
            hour += piles[i]/speed;
            if(piles[i]%speed!=0)
            {
                hour++;
            }
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed=1;
        long max_speed=*max_element(piles.begin(),piles.end());
        int n=piles.size();
        int ans=-1;
        while(min_speed<=max_speed)
        {
            long mid=min_speed+(max_speed-min_speed)/2;
            if(reqHour(piles,mid)<=h)
            {
                ans=mid;
                max_speed=mid-1;
            }
            else{
                min_speed=mid+1;
            }
        }
        return ans;
    }
};