class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> stringArr;
        for (int& a : nums) {
            stringArr.push_back(to_string(a));
        }
        sort(stringArr.begin(), stringArr.end(),
             [](const string& a, const string& b) { return a + b > b + a; });

        if (stringArr[0] == "0")
            return "0";

        string ans = "";
        for (string& s : stringArr) {
            ans += s;
        }
        return ans;
    }
};