class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowel = 0;
        int max = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                vowel++;
            }
        }
        max=vowel;
        for(int i=1;i<n-k+1;i++)
        {
            if (s[i-1] == 'a' || s[i-1] == 'e' || s[i-1] == 'i' || s[i-1] == 'o' || s[i-1] == 'u'){
                vowel--;
            }
            if(s[i+k-1] == 'a' || s[i+k-1] == 'e' || s[i+k-1] == 'i' || s[i+k-1] == 'o' || s[i+k-1] == 'u'){
                vowel++;
            }
            if(vowel>max){
                max=vowel;
            }
        }
        return max;
    }
};