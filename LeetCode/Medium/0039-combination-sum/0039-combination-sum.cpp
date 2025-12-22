class Solution {
public:
    vector<vector<int>> answer={};
    
    void helperCombi(vector<int>& candidates, int target,int start,vector<int>&current)
    {
        if(target==0)
        {
            answer.push_back(current);
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            if(target>=candidates[i])
            {
                current.push_back(candidates[i]);
                helperCombi(candidates,target-candidates[i],i,current);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current={};
        // sort(candidates.begin(),candidates.end());
        helperCombi(candidates,target,0,current);

        return answer;
    }
};