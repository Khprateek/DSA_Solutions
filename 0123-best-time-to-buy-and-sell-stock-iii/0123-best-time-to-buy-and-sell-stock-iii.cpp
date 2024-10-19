class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i= n-1; i >= 0; i--){
            for(int bd = 0; bd < 2; bd++ ){
                for(int life = 1; life < 3; life++){
                    int profit  =0;
                    if(bd){
                        profit = max(-prices[i] + dp[i+1][0][life],dp[i+1][1][life]);
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][life-1],dp[i+1][0][life]);
                    }
                    dp[i][bd][life] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};