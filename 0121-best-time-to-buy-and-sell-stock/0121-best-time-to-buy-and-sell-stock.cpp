class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int sell;
        int profit;
        int maxprofit=0;
        for(int i=1;i<prices.size();i++)
        {
            sell=prices[i];
            profit=sell-buy;
            maxprofit=max(profit,maxprofit);
            if(profit<0)
            {
                buy=sell;
            }
        }
        return maxprofit;
    }
};