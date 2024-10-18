class Solution {
    private:
    int sus(int ind,int bd,int life,int n,vector<int>& prices, vector<vector<int>> & dp){
        if(ind == n) return 0;
        if(life == 0) return 0;
        int profit  = 0;
        if(dp[ind][bd] != -1) return dp[ind][bd];
        if(bd){
            profit = max(-prices[ind] + sus(ind+1,0,life,n,prices,dp),sus(ind+1,1,life,n,prices,dp));
        }
        else{
            profit = max(prices[ind] + sus(ind+1,1,life-1,n,prices,dp), sus(ind+1,0,life,n,prices,dp));
        }
        return dp[ind][bd] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return sus(0,1,3,n,prices,dp);
    }
};