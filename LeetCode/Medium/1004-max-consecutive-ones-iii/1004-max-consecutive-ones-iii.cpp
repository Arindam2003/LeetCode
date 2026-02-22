class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0,zero=0;
        int n=nums.size();
        int ans=0;
        while(i<n)
        {
            // 1.push first
            dq.push_back(nums[i]); 

            // 2.zero cont
            if(nums[i]==0)
            {
                zero++;
            }

            // 3.shrink window
            while(!dq.empty() && zero>k)
            {
                if(dq.front()==0)
                {
                    zero--;
                }
                dq.pop_front();
            }

            //4. check max size
            int len=dq.size();
            ans=max(ans,len);

            i++;
        }
        return ans;
    }
};