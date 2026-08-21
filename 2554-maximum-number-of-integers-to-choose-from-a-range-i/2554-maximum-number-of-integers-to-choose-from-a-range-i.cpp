class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for(auto ban:banned)
        {
            st.insert(ban);
        }

        int sum=0;
        int count=0;

        for(int i=1;i<=n;i++)
        {
            if(sum+i<=maxSum && st.find(i)==st.end())
            {
                sum+=i;
                count++;
            }
        }
        return count;
    }
};