class NumMatrix {
public:
    vector<vector<int>> prefixMatrix;
    vector<int> preSum(vector<int>row)
    {   
        int n=row.size();
        vector<int> prefixRow(n,0);
        prefixRow[0]=row[0];
        for(int i=1;i<row.size();i++)
        {
            prefixRow[i]=prefixRow[i-1]+row[i];
        }
        return prefixRow;
    }

    NumMatrix(vector<vector<int>>& matrix) {
        for(auto row:matrix)
        {
            prefixMatrix.push_back(preSum(row));
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for(int r = row1; r <= row2; r++)
        {
            if(col1 == 0)
                sum += prefixMatrix[r][col2];
            else
                sum += prefixMatrix[r][col2] - prefixMatrix[r][col1 - 1];
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */