class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;

        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        unordered_set<int>check;
        for(auto& [num,count_num] : mpp)
        {
            if(check.count(count_num))
            {
                return false;
            }
            check.insert(count_num);
        }
        return true;
    }
};