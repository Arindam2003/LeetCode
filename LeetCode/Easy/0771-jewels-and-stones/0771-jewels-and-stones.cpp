class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt=0;
        for(int i=0;i<jewels.size();i++)
        {
            int temp=count(stones.begin(),stones.end(),jewels[i]);
            cnt+=temp;
        }
        return cnt;
    }
};