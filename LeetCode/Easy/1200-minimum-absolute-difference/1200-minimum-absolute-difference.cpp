class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;

        sort(arr.begin(),arr.end());
        int min_diff=INT_MAX;
        for(int i=0;i<arr.size()-1;i++)
        {
            min_diff=min(abs(arr[i]-arr[i+1]),min_diff);
        }

        for(int i=0;i<arr.size()-1;i++)
        {
            if(abs(arr[i]-arr[i+1])==min_diff)
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};