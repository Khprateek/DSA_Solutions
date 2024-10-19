class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int prev0 = 0;
        int prev1 = 0;
        for(int ind = n-1; ind >= 0 ; ind--){
            for(int bd = 0; bd < 2; bd++){
                if(bd){
                    prev1 = max(-prices[ind] + prev0 - fee, prev1);
                }
                else{
                    prev0 = max(prices[ind] + prev1, prev0);
                }  
            }
        }
        return prev1;
    }
};