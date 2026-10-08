class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.size();
        if(n==0 || n==1)
        {
            return n;
        }
        unordered_map<char,int> mp;
        int ans=0;
        while(j<n)
        {   
            if(mp[s[j]])
            {
                while(mp[s[j]])
                {
                    
                        mp[s[i]]--;
                    
                    i++;
                }
                mp[s[j]]++;
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                mp[s[j]]++;
                ans = max(ans, j - i + 1);
                j++;
            }
        }
        return ans;
    }
};