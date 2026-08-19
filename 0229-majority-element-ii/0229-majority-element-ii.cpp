class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1=0,elem2=0;
        int count1=0,count2=0;

        for(int num:nums)
        {
            if(num==elem1)
            {
                count1++;
            }else if(num==elem2)
            {
                count2++;
            }else if(count1==0)
            {
                elem1=num;
                count1=1;
            }else if(count2==0)
            {
                elem2=num;
                count2=1;
            }else {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int num:nums)
        {
            if(num==elem1)
            {
                count1++;
            }
            if(num==elem2)
            {
                count2++;
            }
        }
        int n=nums.size();
        vector<int> ans;
        if(count1>n/3){
            ans.push_back(elem1);
        }
        if(count2>n/3 && elem1!=elem2)
        {
            ans.push_back(elem2);
        }
        return ans;
    }
};