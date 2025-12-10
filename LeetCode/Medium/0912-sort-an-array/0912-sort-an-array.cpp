class Solution {
public:
    vector<int>merge2sorted(vector<int>left,vector<int>right)
    {
        int l=left.size();
        int r=right.size();
        int i=0,j=0;
        vector<int>ans;
        while(i<l && j<r)
        {
            if(left[i]<=right[j])
            {
                ans.push_back(left[i]);
                i++;
            }else
            {
                ans.push_back(right[j]);
                j++;
            }
        }

        while(i<l)
        {
            ans.push_back(left[i]);
            i++;
        }

        while(j<r)
        {
            ans.push_back(right[j]);
            j++;
        }

        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        {
            return nums;
        }

        vector<int> left(nums.begin(),nums.begin()+n/2);
        vector<int>right(nums.begin()+n/2,nums.end());

        left=sortArray(left);
        right=sortArray(right);

        return merge2sorted(left,right);
    }
};