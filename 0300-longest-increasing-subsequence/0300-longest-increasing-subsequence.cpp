class Solution {
    private:
    int sus(int ind,int prev,int n, vector<int>& nums,vector<vector<int>> &dp){
        if(ind < 0) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        int pick = 0;
        int notpick = sus(ind-1,prev,n,nums,dp);
        if(prev == n || nums[ind] < nums[prev]){
            pick = 1 + sus(ind-1,ind,n,nums,dp);
        }
        return dp[ind][prev] = max(pick,notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind = n-1 ; ind >= 0; ind--){
            for(int prev = ind-1; prev >= -1; prev--){
                int pick = 0;
                int notpick = dp[ind+1][prev+1];
                if(prev == -1 || nums[ind] > nums[prev]){
                    pick = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(pick,notpick);
            }
        }
        return dp[0][0];
    }
};