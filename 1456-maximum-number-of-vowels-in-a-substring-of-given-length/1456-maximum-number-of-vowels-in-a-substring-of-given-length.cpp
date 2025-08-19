class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowel = 0;
        int maxi = 0;

        for (int i = 0; i < k; i++) {
            if(isVowel(s[i])){
                vowel++;
            }
        }
        maxi = vowel;

        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) {
                vowel++;
            }
            if (isVowel(s[i - k])) {
                vowel--;
            }
            maxi = max(maxi, vowel);
        }

        return maxi;
    }
};