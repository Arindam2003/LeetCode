class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<vector<char>> answer = {};
        for (int i = 0; i < numRows; i++) {
            vector<char> currentRow = {};
            answer.push_back(currentRow);
        }

        int rowIndex = 0;
        int turn = 0;
        for (int i = 0; i < s.size(); i++) {
            answer[rowIndex].push_back(s[i]);
            if (turn == 0) // Down
            {
                rowIndex++;
                if (rowIndex == numRows) {
                    rowIndex = rowIndex - 2;
                    turn = 1;
                }
            } else // up
            {
                rowIndex--;
                if (rowIndex == -1) {
                    rowIndex = rowIndex + 2;
                    turn = 0;
                }
            }
        }
        string ans = "";
        for (int i = 0; i < answer.size(); i++) {
            for (int j = 0; j < answer[i].size(); j++) {
                ans += answer[i][j];
            }
        }
        return ans;
    }
};