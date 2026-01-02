class Solution {
public:
    bool isValid(vector<int>&nums,int h,int mid)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt += (nums[i] + mid - 1) / mid;
            if(cnt>h)
            {
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1, end = *max_element(piles.begin(), piles.end());
        int ans=end;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isValid(piles, h, mid) == true) {
                ans = min(mid,ans);
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};