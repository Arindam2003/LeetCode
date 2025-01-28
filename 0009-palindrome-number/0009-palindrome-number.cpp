class Solution {
public:
    int reverse_number(int num)
    {
        long long ans=0;
        while(num)
        {
            ans=(ans*10)+num%10;
            num=num/10;
        }
        return ans;
    }
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        if(x==reverse_number(x))
        {
            return true;
        }
        else{
            return false;
        }
    }
};