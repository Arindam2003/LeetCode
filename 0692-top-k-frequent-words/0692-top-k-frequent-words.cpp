class Solution {
public:
    typedef pair<int,string> P;
    struct cmp{
        bool operator()(const P&a,const P&b){
            if(a.first==b.first)
            {
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;// string,int
        for(int i=0;i<words.size();i++)
        {
            mpp[words[i]]++;
        }

        priority_queue<P,vector<P>,cmp> pq;

        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<string> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};