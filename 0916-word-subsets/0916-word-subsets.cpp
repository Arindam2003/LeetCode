class Solution {
public:
    void setMax(vector<int> &freq_word2,vector<int>&freq)
    {
        for(int i=0;i<26;i++)
        {
            freq_word2[i]=max(freq_word2[i],freq[i]);
        }
    }
    bool isuniversal(vector<int> & freq_word,vector<int > freq_word2)
    {
        for(int i=0;i<26;i++)
        {
            if(freq_word[i]<freq_word2[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq_words2(26);
        for(string word: words2)
        {
            vector<int>freq(26);
            for(char c: word)
            {
                freq[c-'a']++;
            }
            setMax(freq_words2,freq);
        }

        vector<string> universal;
        for(string word: words1)
        {
            vector<int>freq_word(26);
            for(char c: word)
            {
                freq_word[c-'a']++;
            }
            if(isuniversal(freq_word,freq_words2))
            {
                universal.push_back(word);
            }
        }
        return universal;

        
    }
};