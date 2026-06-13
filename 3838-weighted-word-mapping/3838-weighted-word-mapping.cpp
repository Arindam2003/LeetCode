class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char, int> mpp;

        for (int i = 0; i < 26; i++) {
            mpp['a' + i] = weights[i];
        }

        string ans;

        for (string &word : words) {
            int sum = 0;

            for (char ch : word) {
                sum += mpp[ch];
            }

            int rem = sum % 26;
            ans.push_back('z' - rem);
        }

        return ans;
    }
};