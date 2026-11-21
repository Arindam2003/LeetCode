class Solution {
public:
    int minRange(int a, int b, int c) {
        int prev=max({a,b,c})-min({a,b,c});

        if(a>b && a>c)
        {
            a=b+c;
        }else if(b>a && b>c){
            b=a+c;
        }else{
            c=a+b;
        }

        int ans=max({a,b,c})-min({a,b,c});

        return min(ans,prev);
    }
};