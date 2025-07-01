class Solution {
    long long nCr(int n, int r) {
        if (r > n - r) r = n - r;

        long long res = 1;
        for (int i = 0; i < r; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++)
        {   
            vector<int> subans;
            for(int j=0;j<=i;j++)
            {
                subans.push_back(nCr(i,j));
            }
            ans.push_back(subans);
        }
        return ans;
    }
};