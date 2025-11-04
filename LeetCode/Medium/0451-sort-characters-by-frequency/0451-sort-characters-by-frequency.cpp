class Solution {
public:
    string frequencySort(string s) {
        vector<int>hash(256,0);
        // a->97
        // A->65
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]]++;
        }
        vector<pair<int,char>>freqArr={};
        for(int i=0;i<256;i++)
        {
            if(hash[i]!=0){
            freqArr.push_back({hash[i],(char)i});
            }
        }

        sort(freqArr.begin(),freqArr.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });

        string ans="";
        for(int i=0;i<freqArr.size();i++)
        {
            while(freqArr[i].first>0)
            {
                ans+=freqArr[i].second;
                freqArr[i].first--;
            }
        }
        return ans;
    }
};