class Solution {
public:
    double myPowHelper(double x, long long n){
        if(n==0)
        {
            return 1.0;
        }
        double partial_ans=myPowHelper(x,n/2);
        if(n%2==0)
        {
            return partial_ans*partial_ans;
        }
        else{
            return x*partial_ans*partial_ans;
        }
    }

    double myPow(double x, long long n) {
        if(n<0)
        {   
            return 1/myPowHelper(x,-n);
        }else{
            return myPowHelper(x,n);
        }
    }
};