class Solution {
public:
    int maxProduct(int n) {
        int maxi=-1;
        int secMaxi=-1;

        while(n)
        {
            int d=n%10;
            if(d>maxi)
            {
                secMaxi=maxi;
                maxi=d;
            }else if(d>secMaxi)
            {
                secMaxi=d;
            }
            n=n/10;
        }

        return maxi*secMaxi;
    }
};