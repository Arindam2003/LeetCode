class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m={};
        m[0]=1; // this is for checking is it 
        int answer=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            answer+=m[sum-k]; // is m[3] present +1|+2 else +0 
            m[sum]++;
        }
        return answer;
    }
};