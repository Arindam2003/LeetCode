class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            // empty stack
            if (st.empty()) {
                st.push({s[i], 1});
            } else {
                // stack top element check
                if (st.top().first == s[i]) {
                    int freq = st.top().second;
                    st.pop();
                    st.push({s[i], freq + 1});
                } else {
                    st.push({s[i], 1});
                }
            }

            if (st.top().second == k) {
                st.pop();
            }
        }
        string result = "";

        while (!st.empty()) {
            pair<char, int> topElem = st.top();
            st.pop();
            while (topElem.second > 0) {
                result += topElem.first;
                topElem.second--;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};