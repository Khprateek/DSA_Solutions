class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0] = nums[0];
        dp[1][0] = max(nums[0], nums[1]);
        dp[1][1] = nums[1];
        for(int ind =2; ind < n; ind++){
            for(int last = 0;last <2;last++){

                int notpick = dp[ind-1][last];
                int pick = nums[ind] + dp[ind-2][last];

                if(ind == n-1 && last == 0){
                    dp[ind][last] = notpick;
                }
                else{
                    dp[ind][last] = max(pick,notpick);
                }
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};