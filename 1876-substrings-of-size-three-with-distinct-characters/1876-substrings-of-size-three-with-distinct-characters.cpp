class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int> mpp;
    int count=0;
        int l=0;
        for(int r=0;r<s.size();r++)
        {
            mpp[s[r]]++;
            if(r-l+1>3)
            {
                mpp[s[l]]--;
                if(mpp[s[l]]==0)
                {
                    mpp.erase(s[l]);
                }
                l++;
            }

            if(r-l+1==3 && mpp.size()==3)
            {
                count++;   
            }
        }
        return count;
    }
};