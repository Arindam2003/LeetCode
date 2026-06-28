class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> ch;
        for(auto i:s)
        {
            ch[i]++;
        }

        string vow="aeiou";
        // string cons="bcdfghjklmnpqrstvwxyz";
        int maxV=0;
        int maxC=0;
        for(auto i:s)
        {
            if(vow.find(i)!=string::npos)//vowel
            {
                int count=ch[i];
                // cout<<count<<endl;
                maxV=max(maxV,count);
            }
            else
            {
                int count=ch[i];
                                // cout<<count<<endl;

                maxC=max(maxC,count);
            }
        }

        return maxV+maxC;
    }
};