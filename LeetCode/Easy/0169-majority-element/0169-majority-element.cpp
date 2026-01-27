class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int elem;

        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                cnt++;
                elem=nums[i];
            }
            else if(elem==nums[i])
            {
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return elem;
    }
};