class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        int left=0;
        int count=0;
        for(int right=0;right<n;right++)
        {
            mpp[s[right]]++;

            if(right-left+1>3)
            {
                mpp[s[left]]--;
                if(mpp[s[left]]==0)
                {
                    mpp.erase(s[left]);
                }
                left++;
            }


            if(right-left+1==3 && mpp.size()==3)
            {
                count++;
            }
        }
        return count;
    }
};