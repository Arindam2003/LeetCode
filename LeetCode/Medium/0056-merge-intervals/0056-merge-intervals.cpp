class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans={};

        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        
        for(int i=0;i<intervals.size();i++)
        {
            if(ans.size()==0)
            {
                ans.push_back(intervals[0]);
            }else{
                int l=ans[ans.size()-1][0];
                int r=ans[ans.size()-1][1];
                if(intervals[i][0]>=l && intervals[i][0]<=r)
                {
                    ans[ans.size()-1][1]=max(r,intervals[i][1]);
                }else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};