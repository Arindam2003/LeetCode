class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int maxlen=-1;
        for(int j=1;j<n;j++)
        {
            int m=j-i+1;
            int expdiff = (m % 2 == 0) ? 1 : -1;
            if(nums[j]-nums[j-1]==expdiff)
            {
                maxlen=max(maxlen,m);
            }
            else{
                if (nums[j] - nums[j - 1] == 1) {
                    i = j - 1; 
                    maxlen = max(maxlen, 2); 
                }
                else {
                    i = j; 
                }
            }
            
        }
        return maxlen;
    }
};