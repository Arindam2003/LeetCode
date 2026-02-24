class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int n=nums.size();
        queue<int> q;
        int ans=INT_MAX;
        int sum=0;

        while(i<n)
        {
            q.push(nums[i]);
            sum+=nums[i];
            while(!q.empty() && sum>=target)
            {
                ans=min(ans,(int)q.size());
                sum-=q.front();
                q.pop();
            }

            
            i++;
        }
        return ans==INT_MAX?0:ans;
    }
};