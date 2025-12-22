class Solution {
public:
    vector<vector<int>> answer={};
    vector<int> current={};

    void subsetHelper(vector<int> &nums,int index)
    {

        if(index==nums.size())
        {
            answer.push_back(current);
            return;
        }

        // i have two option
        // taking the elements.. 
        current.push_back(nums[index]);
        subsetHelper(nums,index+1);

        // backtrack or remove the last element
        current.pop_back();
        subsetHelper(nums,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        subsetHelper(nums,0);
        return answer;
    }
};