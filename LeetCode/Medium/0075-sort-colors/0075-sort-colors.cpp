class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int z=0,o=0,t=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                z++;
            }
            else if(nums[i]==1)
            {
                o++;
            }
            else if(nums[i]==2)
            {
                t++;
            }
        }
        cout<<z<<o<<t;
        int k=0;
        int i=0;
        while(k<n && i<z)
        {
            nums[k++]=0;
            i++;
        }
        i=0;
        while(k<n && i<o)
        {
            nums[k++]=1;
            i++;
        }
        i=0;
        while(k<n && i<t)
        {
            nums[k++]=2;
            i++;
        }
    }
};