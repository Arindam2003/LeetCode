class Solution {
public:
    int mySqrt(int x) {
        int st=1,end=x;
        int ans=0;
        while(st<=end)
        {
            long long mid = st + (end - st) / 2;
            long long temp=mid*mid*1LL;
            if(temp==x)
            {
                return mid;
            }else if(temp>x)
            {
                end=mid-1;
            }
            else{
                ans=mid;
                st=mid+1;
            }
        }
        return ans;
    }
};