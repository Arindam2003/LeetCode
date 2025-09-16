class Solution {
public:
    int sumArray(vector<int> arr)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
        return sum;
    }
    int diagonalSum(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int> primary;
        vector<int> secondary;

        for(int i=0;i<row;i++)
        {
            for( int j=0;j<col;j++)
            {
                if(i==j){
                    primary.push_back(mat[i][j]);
                    secondary.push_back(mat[i][col-1-j]);
                }
            }
        }
        int total=sumArray(primary)+sumArray(secondary);
        if(row%2!=0)
        {
            int index=row/2;
            return total-mat[index][index];
        }
        else{
            return total;
        }
    }
};