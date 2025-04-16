class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        int j=-1;
        int i;
        for(i=n-1;i>=0;i--)
        {
            if((num[i]-'0')%2==1)
            {
                j=i;
                break;
            }
        }
        i=0;
        while(i<j && num[i]!='0')
        {
            break;
        }
        return num.substr(i,j-i+1);
    }
};