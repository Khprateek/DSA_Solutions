class Solution {
    private:
    int sus(int ind,int bd, int n,vector<int> &prices, vector<vector<int>> &dp){
        if(ind >= n) return 0;
        int profit = 0;
        if(dp[ind][bd] != -1) return dp[ind][bd];
        if(bd){
            profit = max(-prices[ind] + sus(ind+1,0,n,prices,dp),sus(ind+1,1,n,prices,dp));
        }
        else{
            profit = max(prices[ind] + sus(ind+2,1,n,prices,dp),sus(ind+1,0,n,prices,dp));
        }
        return dp[ind][bd] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int ind = n-1; ind >= 0; ind--){
            for(int bd =0; bd < 2; bd++){
                int profit = 0;
                if(bd){
                    profit = max(-prices[ind] + dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+2][1],dp[ind+1][0]);
                }
                dp[ind][bd] = profit;
            }
        }
        return dp[0][1];
    }
};