class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        n--;
        while(n>=0)
        {
            if((num[n]-'0')%2!=0)
            {
                return num.substr(0,n+1);
            }
            n--;
        }

        return "";

    }
};