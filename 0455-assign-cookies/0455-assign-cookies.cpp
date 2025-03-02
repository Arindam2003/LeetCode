class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gsize=g.size();
        int csize=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int greed=0;
        int coo=0;
        while(coo<csize && greed < gsize)
        {
            if(s[coo]>=g[greed])
            {
                greed++;
            }
            coo++;
        }
        return greed;
    }
};