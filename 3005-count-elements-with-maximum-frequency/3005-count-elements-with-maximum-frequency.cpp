class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        int max_elem=*max_element(nums.begin(),nums.end());
        vector<int> hash(max_elem+1,0);
        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
        }
        int max_count=hash[0];
        int count=0;
        int n_hash=hash.size();
        for(int i=1;i<n_hash;i++)
        {
            if(hash[i]>max_count)
            {
                max_count=hash[i];
                count=hash[i];
            }else if(hash[i]==max_count)
            {
                count+=hash[i];
            }
        }
        return count;

    }
};