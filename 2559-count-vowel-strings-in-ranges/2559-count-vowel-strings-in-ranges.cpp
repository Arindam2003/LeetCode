class Solution {
public:
    bool isVowel (string s,int n)
    {
        if((s[0]== 'a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')&& (s[n-1]== 'a'||s[n-1]=='e'||s[n-1]=='i'||s[n-1]=='o'||s[n-1]=='u'))
        {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries){
        int n=words.size();
        vector<int> vowel(n,0);
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++)
        {
            if(isVowel(words[i],words[i].size()))
            {
                vowel[i]=1;
            }
            else{
                vowel[i]=0;
            }
        }
        prefix[0]=vowel[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=vowel[i]+prefix[i-1];
        }
        int m=queries.size();
        vector <int> ans(m,0);
        for(int i=0;i<m;i++)
        {
            int st=queries[i][0];
            int end=queries[i][1];
            if(st==0)
            {
                ans[i]=prefix[end];
            }
            else {
                ans[i]=prefix[end]-prefix[st-1];
            }
        }
        return ans;
    }
};