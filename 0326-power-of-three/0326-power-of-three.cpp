class Solution {
public:
    int helper(int n)
    {
        if(n<=0) return false;
        if(n==1) return true;
        if(n%3!=0) return false;
        return helper(n/3);
    }
    bool isPowerOfThree(int n) {
        return helper(n);
    }
};