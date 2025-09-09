class Solution {
    bool binarySearch(vector<int> row,int target)
    {
        int r=row.size()-1;
        int l=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(target==row[mid])
            {
                return true;
            }else if(target>row[mid])
            {
                l=mid+1;
            }else{
                r=mid-1;
            }
        } 
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowFirst=0;
        int rowLast=matrix.size()-1;
        int colno=matrix[0].size()-1;
        int ansRow;
        while(rowFirst<=rowLast)
        {
            int mid=rowFirst+(rowLast-rowFirst)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][colno])
            {
                ansRow=mid;
                break;
            }
            else if(target>matrix[mid][0])
            {
                rowFirst=mid+1;
            }
            else{
                rowLast=mid-1;
            }
        }
        return binarySearch(matrix[ansRow],target);
    }
};