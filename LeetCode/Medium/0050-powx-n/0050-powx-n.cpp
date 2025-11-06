class Solution {

public:
    double helper(double x, int n) {
        if(n==0) return 1;
        double half= helper(x,n/2);
        if(n%2==0)
        {
            return half*half;
        }else{
            return x*half*half;
        }
    }

    double myPow(double x, int n) {
        long long exp=n;
        if(exp<0)
        {
            x=1/x;
            exp=-exp;
        }
        return helper(x,exp);
    }
};