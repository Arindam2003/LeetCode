class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int n=nums.size();
        deque<int>q;

        vector<int> ans={};

        // first part only for k size window
        while(i<k)
        {
            //  q is not empty and 
            // current elem> previous ds element
            while(!q.empty() && nums[i]>nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);
            i++;
        }

        while(i<n)
        {
            ans.push_back(nums[q.front()]);

            while(!q.empty() && q.front()<=(i-k))
            {
                q.pop_front();
            }


            //  q is not empty and 
            // current elem> previous ds element
            while(!q.empty() && nums[i]>nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);
            i++;
        }
        ans.push_back(nums[q.front()]);
        return ans;
    }
};