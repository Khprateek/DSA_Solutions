class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev0 = 0;
        int prev1 = 0;
        for(int ind = n-1; ind >= 0; ind--){
            for(int bb = 0; bb < 2; bb++){
                if(bb == 1){
                    prev1 = max(-prices[ind] + prev0, prev1);
                }
                else{
                    prev0 = max(prices[ind] + prev1, prev0);
                }
            }
        }
        return prev1;
    }
};