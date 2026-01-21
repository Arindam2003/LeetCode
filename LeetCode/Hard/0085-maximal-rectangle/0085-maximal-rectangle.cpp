class Solution {
public:
    vector<int> rightSmaller(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            } else {
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> leftSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            } else {
                ans[i] = -1;
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightPart = rightSmaller(heights);
        vector<int> leftPart = leftSmaller(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = (rightPart[i] - leftPart[i] - 1);
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int N = matrix.size();    // row
        int M = matrix[0].size(); // col
        vector<vector<int>> mat(N, vector<int>(M, 0));

        for (int i = 0; i < M; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                if (matrix[j][i] == '1') {
                    sum++;
                } else {
                    sum = 0;
                }

                mat[j][i] = sum;
            }
        }
        int answer = 0;
        for (int i = 0; i < N; i++) {
            int area = largestRectangleArea(mat[i]);
            answer = max(answer, area);
        }

        return answer;
    }
};