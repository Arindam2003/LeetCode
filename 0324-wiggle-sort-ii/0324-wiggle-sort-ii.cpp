class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int mid=(nums.size()+1)/2;
        int j=nums.size()-1;
        int l=mid-1;
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                nums[i]=temp[l--];
            }else{
                nums[i]=temp[j--];
            }
        }
    }
};