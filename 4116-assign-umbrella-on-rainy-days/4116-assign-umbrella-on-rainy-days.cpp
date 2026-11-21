class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n=rain.size();
        vector<string> ans={};
        int alice=0;
        int bob=0;
        for(int i=0;i<n-1;i++)
        {
            if(rain[i]==0)
            {
                ans.push_back("None");
            }
            else if(rain[i]==1 && rain[i+1]==1)
            {
                if(bob<alice)
                {
                    ans.push_back("Bob");
                    bob++;
                }else{
                    ans.push_back("Alice");
                    alice++;
                }
            }else if(rain[i]==1)
            {
                ans.push_back("Bob");
                bob++;
            }
        }
        if(rain[n-1]==1)
        {
            ans.push_back("Bob");
        }else
        {
            ans.push_back("None");
        }

        return ans;
    }
};