class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row=accounts.size();
        int col=accounts[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<row;i++)
        {
            int rowSum=0;
            for(int j=0;j<col;j++)
            {
                rowSum+=accounts[i][j];
            }
            maxi=max(maxi,rowSum);
        }
        return maxi;
    }
};