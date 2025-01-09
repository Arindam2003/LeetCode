class Solution {
public:
    bool isprefix(string &s1,string &s2)
    {
        int n1=s1.size();  //word
        int n2=s2.size(); //check
        if(n2>n1)
        {
            return false;
        }
        for(int i=0;i<n2;i++)
        {
            if(s1[i]!=s2[i])
            {
                return false;
            }
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            if(isprefix(words[i],pref))
            {
                count++;
            }
        }
        return count;
    }
};