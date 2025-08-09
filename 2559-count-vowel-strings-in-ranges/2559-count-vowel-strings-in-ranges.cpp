class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> check(n, 0);
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (int i = 0; i < n; i++) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                check[i] = 1;
            }
        }
        vector<int> sum;
        sum.push_back(check[0]);
        for (int i=1;i<check.size();i++)
        {
            sum.push_back(sum[i-1] + check[i]);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            if(queries[i][0]>0)
            {
                ans.push_back(sum[queries[i][1]]-sum[queries[i][0]-1]);
            }
            else if(queries[i][0]==0){
                ans.push_back(sum[queries[i][1]]);
            }
        }
        return ans;
    }
};