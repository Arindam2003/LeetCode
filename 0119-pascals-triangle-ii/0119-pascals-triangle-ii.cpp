class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        long long val = 1; // Use long long to avoid overflow

        for (int i = 0; i <= rowIndex; i++) {
            row[i] = val;
            val = val * (rowIndex - i) / (i + 1);
        }

        return row;
    }
};