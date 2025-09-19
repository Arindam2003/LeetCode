class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()<num2.size())
        {
            swap(num1,num2);
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string result;
        int carry=0;
        for(int i=0;i<num1.size();i++)
        {
            int digit1=num1[i]-'0';
            int digit2;
            if(i<num2.size())
            {
                digit2=num2[i]-'0';
            }else{
                digit2=0;
            }

            int sum=digit1+digit2+carry;

            result.push_back(sum%10+'0');
            carry=sum/10;
        }
        if (carry) result.push_back(carry + '0');
        reverse(result.begin(),result.end());
        return result;
    }
};