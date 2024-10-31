class Solution {
    private:
    int sus(int ind,vector<int>& nums,bool last,vector<vector<int>> &dp){
        if(ind < 0) return 0;
        if(ind == 0){
            if(last){
                return 0;
            }
            else{
                return nums[0];
            }
        }
        if(dp[ind][last] != -1) return dp[ind][last];
        int notpick = sus(ind-1,nums,last,dp);
        if(ind == nums.size()-1) last = true;
        int pick = nums[ind] + sus(ind-2,nums,last,dp);
        return dp[ind][last] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        bool last = false;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return sus(n-1,nums,last,dp);
    }
};