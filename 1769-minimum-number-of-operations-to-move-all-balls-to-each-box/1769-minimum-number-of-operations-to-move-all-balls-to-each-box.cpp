class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n =boxes.size();
        vector<int>result(n);
        int before=0;
        int after=0;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1')
            {
                after++;
                result[0]=result[0]+i;
            }
        }

        if(boxes[0]=='1')
        {
            after--;
            before++;
        }
        for(int i=1;i<boxes.size();i++)
        {
            result[i]+=result[i]+result[i-1]-after+before;
            if(boxes[i]=='1')
            {
                after--;
                before++;
            }
        }
        return result;
    }
};