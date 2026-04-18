class Solution {
public:
    vector<string> ans;

    void backtrack(string &digits, int index, string &current, vector<string> &mapping) {
        // base case
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            current.push_back(ch);              // choose
            backtrack(digits, index + 1, current, mapping); // explore
            current.pop_back();                // un-choose (backtrack)
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "",      // 0,1
            "abc",       // 2
            "def",       // 3
            "ghi",       // 4
            "jkl",       // 5
            "mno",       // 6
            "pqrs",      // 7
            "tuv",       // 8
            "wxyz"       // 9
        };

        string current = "";
        backtrack(digits, 0, current, mapping);

        return ans;
    }
};