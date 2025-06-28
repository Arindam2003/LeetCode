class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();     //! row
        int m = matrix[0].size();  //! col
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=ans[i][j];
            }
        }
    }
};