class Solution {
public:
    bool check(vector<int>& nums) {
        int first=nums[0];
        int last=nums[nums.size()-1];
        int curr,next;
        int count=0;
        if(first<last){
            for(int i=0;i<nums.size();i++)
            {
                next=nums[i];
                if(next<curr){
                    return false;
                }
                curr=next;
            }
        }
        else{
            for(int i=0;i<nums.size();i++)
            {
                next=nums[i];
                if(next<curr){
                    count++;
                }
                curr=next;
            }
            if(count>1){
                return false;
            }
            return true;
        }
        return true;
    }
};