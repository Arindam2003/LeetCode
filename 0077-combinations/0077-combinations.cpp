class Solution {
public:
    vector<vector<int>> result={};

    void helper(int i,int n,int k,vector<int>&temp)
    {
        if(k==0)
        {
            result.push_back(temp);
            return;
        }

        if(i>n)
        {
            return;
        }

        temp.push_back(i);
        helper(i+1,n,k-1,temp);
        temp.pop_back();
        helper(i+1,n,k,temp);
    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> temp={};

        helper(1,n,k,temp);
        return result;
    }
};