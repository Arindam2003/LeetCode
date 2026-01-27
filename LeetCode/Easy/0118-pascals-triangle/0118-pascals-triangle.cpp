class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans={};
        vector<int> first={};
        first.push_back(1);
        ans.push_back(first);
        int middle=0; // counting the middle element...

        for(int i=1;i<numRows;i++)
        {
            vector<int> current={};
            current.push_back(1);
            for(int j=1;j<=middle;j++) // generate the middle element
            {
                current.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            middle++;
            current.push_back(1);
            ans.push_back(current);
        }
        return ans;
    }
};