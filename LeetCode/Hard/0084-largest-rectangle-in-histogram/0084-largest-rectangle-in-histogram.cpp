class Solution {
public:
    vector<int> rightSmaller(vector<int>& heights)
    {
        int n=heights.size();
        stack<int>st;
        vector<int> ans(n,n);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }else{
                ans[i]=n;
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> leftSmaller(vector<int>& heights)
    {
        int n=heights.size();
        vector<int> ans(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }else{
                ans[i]=-1;
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>rightPart=rightSmaller(heights);
        vector<int>leftPart=leftSmaller(heights);

        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            int width=(rightPart[i]-leftPart[i]-1);
            int area=heights[i]*width;

            maxArea=max(maxArea,area);
        }

        return maxArea;
    }
};