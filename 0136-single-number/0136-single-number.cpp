class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }
        for (auto& pair : hash) {
            if (pair.second == 1)
                return pair.first;
        }
        return -1;
    }
};