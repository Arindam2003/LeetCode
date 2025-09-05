class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),
        [](vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        });

        int boxLoaded=0;
        int ans=0;
        int i=0;
        while(boxLoaded<truckSize && i<boxTypes.size())
        {
            int empty=truckSize-boxLoaded;
            if(boxTypes[i][0]<=empty)
            {
                ans=ans+(boxTypes[i][0]*boxTypes[i][1]);
                boxLoaded=boxLoaded+boxTypes[i][0];
            }
            else{
                ans=ans+(boxTypes[i][1]*empty);
                boxLoaded=boxLoaded+empty;
            }
            i++;
        }
        return ans;
    }
};