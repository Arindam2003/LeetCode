class Solution {
public:
    vector<string> answer = {};
    vector<char> current = {};
    void recur(int n, int sum, int i) {
        if (i == n) {
            if (sum == 0) {
                string s = "";
                for (int i = 0; i < current.size(); i++) {
                    s += current[i];
                }
                answer.push_back(s);
            }
            return;
        }


        current.push_back('(');
        recur(n, sum + 1, i + 1);
        current.pop_back();

        if (sum > 0) {
            current.push_back(')');
            recur(n, sum - 1, i + 1);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        recur(2 * n, 0, 0);
        return answer;
    }
};