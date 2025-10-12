class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;

        vector<int>firstRow;
        firstRow.push_back(1);
        answer.push_back(firstRow);
        int middleElement=0;
        for(int i=1;i<numRows;i++)
        {
            vector<int>currentRow;
            currentRow.push_back(1);
            for(int j=1;j<=middleElement;j++)
            {
                currentRow.push_back(answer[i-1][j]+answer[i-1][j-1]);
            }
            middleElement++;
            currentRow.push_back(1);
            answer.push_back(currentRow);
        }
        return answer;
    }
};