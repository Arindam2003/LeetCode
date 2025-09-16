class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> ans;
        for(int i=0;i<row;i++)
        {
            int small=INT_MAX;
            int k;
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]<small)
                {
                    small=matrix[i][j];
                    k=j;
                }
            }
            int big=INT_MIN;
            for(int j=0;j<row;j++)
            {
                if(matrix[j][k]>big)
                {
                    big=matrix[j][k];
                }
            }

            if(small==big)
            {
                ans.push_back(small);
            }
        }
        return ans;
    }
};