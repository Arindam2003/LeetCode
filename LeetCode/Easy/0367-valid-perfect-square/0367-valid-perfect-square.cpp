class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;

        long long low=2,high=num/2;

        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            long long sq=mid*mid*1LL;

            if(sq==num)
            {
                return true;
            }
            else if(sq<num)
            {
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
};