class Solution {
public:
    bool isVowel(char ch) {
        ch = std::tolower(ch);
        switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        int maxCount = count;
        for (int st = 1, en = k; en < n; st++, en++) {
            if (isVowel(s[st - 1])) {
                count--;
            }
            if (isVowel(s[en])) {
                count++;
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};