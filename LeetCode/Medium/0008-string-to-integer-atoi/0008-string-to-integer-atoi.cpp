class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int result = 0;
        int sign = 1;
        while (i < n && s[i] == ' ')
            i++; // front space removee

        if (s[i] == '+') {
            sign = 1;
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }
        return result*sign;
    }
};