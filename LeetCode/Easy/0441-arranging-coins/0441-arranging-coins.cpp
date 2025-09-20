class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;
        int left=0;
        int right=n;
        while(left<=right)
        {
            int mid=left+ (right-left)/2;
            long long temp=(1LL * mid*(mid+1))/2;
            if(temp==n)
            {
                return mid;
            }
            if(temp<n)
            {
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return ans;
    }
};