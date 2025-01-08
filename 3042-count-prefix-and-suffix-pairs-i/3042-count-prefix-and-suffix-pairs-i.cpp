class Solution {
    bool isprefix(const string &s1,const string &s2)
    {
        int m=s1.size();
        int n=s2.size();
        if(m>n)
        {
            return false;
        }
        for(int i=0;i<m;i++)
        {
            if(s1[i]!=s2[i])
            {
                return false;
            }
        }
        return true;
    }
    bool issuffix(const string &s1,const string &s2)
    {
        int m=s1.size();
        int n=s2.size();
        if(m>n)
        {
            return false;
        }
        for(int i=m-1;i>=0;i--)
        {
            if(s1[i]!=s2[n-(m-i)])
            {
                return false;
            }
        }
        return true;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int i,j;
        int count=0;
        for (i=0;i<words.size();i++)
        {
            for(j=i+1;j<words.size();j++)
            {
                if(isprefix(words[i],words[j])&& issuffix(words[i],words[j]))
                count++;
            }
        }
        return count;
    }
};