class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int st = 0;
        int end = s.size() - 1;
        while (st <= end) {
            if (isVowel(s[st]) && isVowel(s[end])) {
                swap(s[st], s[end]);
                st++;
                end--;
            } else if (isVowel(s[st]) && !isVowel(s[end])) {
                end--;
            } else if (!isVowel(s[st]) && isVowel(s[end])) {
                st++;
            }else{
                st++;
                end--;
            }
        }
        return s;
    }
};