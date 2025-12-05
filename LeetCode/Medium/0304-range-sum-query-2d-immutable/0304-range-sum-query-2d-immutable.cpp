class NumMatrix {
public:
    vector<vector<int>>preMatrix;
    vector<int> preSum(vector<int> nums)
    {
        int n=nums.size();
        vector<int> ans(n,0);
        ans[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]+nums[i];
        }
        return ans;
    }
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            preMatrix.push_back(preSum(matrix[i]));
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; r++) {
            if (col1 == 0)
                sum += preMatrix[r][col2];
            else
                sum += preMatrix[r][col2] - preMatrix[r][col1 - 1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */