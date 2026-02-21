class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // [2,6,4,8,10,9,15]

        vector<int> sortArr=nums;
        sort(sortArr.begin(),sortArr.end());

        // [2,4,6,8,9,10,15]

        int st=0,en=nums.size()-1;
        bool turn=true;
        while(st<=en)
        {
            if(nums[st]!=sortArr[st])
            {
                turn=false;
                break;
            }
            st++;
        }

        while(en>=0)
        {
            if(nums[en]!=sortArr[en])
            {
                turn=false;
                break;
            }
            en--;
        }
        if(turn == true)
        {
            return 0;
        }

        return en-st+1;
    }
};