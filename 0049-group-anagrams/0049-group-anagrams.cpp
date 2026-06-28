class Solution {
public:
    string generate(string& temp)
    {
        int arr[26]={0};

        for(auto &ch:temp)
        {
            arr[ch-'a']++;
        }

        string res="";
        for(int i=0;i<26;i++)
        {
            int freq=arr[i];
            if(freq>0)
            {
                res+=string(freq,i+'a');
            }
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>>result;

        for(int i=0;i<n;i++)
        {
            string temp=strs[i];
            string new_word=generate(temp);
            mpp[new_word].push_back(strs[i]);
        }

        for(auto a:mpp)
        {
            result.push_back(a.second);
        }

        return result;
    }
};