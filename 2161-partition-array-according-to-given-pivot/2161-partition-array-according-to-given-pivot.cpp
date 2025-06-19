class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans,low,eq,high;
        for(int x:nums){
            if(x<pivot){
                low.push_back(x);
            }
            else if(x==pivot){
                eq.push_back(x);
            }
            else{
                high.push_back(x);
            }
        }

        ans.insert(ans.end(),low.begin(),low.end());
        ans.insert(ans.end(),eq.begin(),eq.end());
        ans.insert(ans.end(),high.begin(),high.end());
        return ans;
    }
};