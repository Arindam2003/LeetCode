class Solution {
public:
    vector<string> res;

    void backtrack(string &s, int start, int parts, string current) {

        if (parts == 4 && start == s.size()) {
            current.pop_back(); 
            res.push_back(current);
            return;
        }

        if (parts == 4 || start == s.size()) return;

        for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
            string part = s.substr(start, len);

            if ((part.size() > 1 && part[0] == '0') || stoi(part) > 255)
                continue;

            backtrack(s, start + len, parts + 1, current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        res.clear();
        backtrack(s, 0, 0, "");
        return res;
    }
};