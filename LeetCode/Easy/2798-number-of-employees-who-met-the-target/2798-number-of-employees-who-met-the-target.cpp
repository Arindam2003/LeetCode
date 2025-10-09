class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n=hours.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(hours[i]>=target)
            {
                count++;
            }
        }
        return count;
    }
};