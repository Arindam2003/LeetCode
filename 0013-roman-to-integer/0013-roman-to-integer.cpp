class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                ans += 1;
            } else if (s[i] == 'V') {
                if (i > 0 && s[i - 1] == 'I') {
                    ans += 3; // +4 - 1 (remove previous I)
                } else {
                    ans += 5;
                }
            } else if (s[i] == 'X') {
                if (i > 0 && s[i - 1] == 'I') {
                    ans += 8; // +9 - 1
                } else {
                    ans += 10;
                }
            } else if (s[i] == 'L') {
                if (i > 0 && s[i - 1] == 'X') {
                    ans += 30; // +40 - 10
                } else {
                    ans += 50;
                }
            } else if (s[i] == 'C') {
                if (i > 0 && s[i - 1] == 'X') {
                    ans += 80; // +90 - 10
                } else {
                    ans += 100;
                }
            } else if (s[i] == 'D') {
                if (i > 0 && s[i - 1] == 'C') {
                    ans += 300; // +400 - 100
                } else {
                    ans += 500;
                }
            } else if (s[i] == 'M') {
                if (i > 0 && s[i - 1] == 'C') {
                    ans += 800; // +900 - 100
                } else {
                    ans += 1000;
                }
            }
        }
        return ans;
    }
};