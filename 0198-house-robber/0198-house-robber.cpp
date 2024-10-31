class Solution {
    private:
    int sus(int ind, vector<int> &nums,vector<int> &dp){
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int notpick = sus(ind-1,nums,dp);
        int pick = nums[ind] + sus(ind-2,nums,dp);
        return dp[ind] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return sus(n-1,nums,dp);
    }
};