class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int profit = 0;
      int L=0;
      int size=prices.size()-1;
      for(int R=1;R<=size;++R){
        if(prices[R]<prices[L]){
            L=R;
        }else{
            profit=max(profit,prices[R]-prices[L]);
        }
      }
      return profit;
    }
};