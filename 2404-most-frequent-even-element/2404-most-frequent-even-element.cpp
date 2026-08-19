class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums)
        {
            mp[num]++;
        }

        int elem=-1;
        int maxfreq=0;
        for(auto it:mp)
        {
            if(it.first%2==0 && it.second>maxfreq)
            {
                elem=it.first;
                maxfreq = it.second;
            }else if(it.first%2==0 && it.second==maxfreq)
            {
                if(it.first<elem)
                {
                    elem=it.first;
                }
            }
        }
        return elem;
    }
};