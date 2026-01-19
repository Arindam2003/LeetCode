class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> ans(n,0);

        for(int i=0;i<n;i++)
        {
            while(st.size()>0 && arr[i]>arr[st.top()])
            {
                ans[st.top()]=i-st.top();
                st.pop();
            }
            
            st.push(i);
        }
        return ans;
    }
};