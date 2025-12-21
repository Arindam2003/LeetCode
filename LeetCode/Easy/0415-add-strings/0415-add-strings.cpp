class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();

        int i=n-1;
        int j=m-1;

        int carry=0;
        string ans;
        while(i>=0 && j>=0)
        {
            int n1= num1[i]-'0';
            int n2= num2[j]-'0';

            int final=n1+n2+carry;

            carry=final/10;

            ans.push_back((final%10)+'0');
            i--;
            j--;
        }

        while(i>=0)
        {
            int n1= num1[i]-'0';

            int final=n1+carry;

            carry=final/10;

            ans.push_back((final%10)+'0');
            i--;
        }

        while(j>=0)
        {
            int n2= num2[j]-'0';

            int final=n2+carry;

            carry=final/10;

            ans.push_back((final%10)+'0'); 
            j--;  
        }
        if (carry) {
            ans.push_back(carry + '0');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};