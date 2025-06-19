class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0; //positive
        int neg=1; //negetive
        int n=nums.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos=pos+2;
            }else{
                ans[neg]=nums[i];
                neg=neg+2;
            }
        }
        return ans;
    }
};