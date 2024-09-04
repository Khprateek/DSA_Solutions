class Solution {
    private:
    int sus(int ind,int pos,vector<vector<int>>& triangle,vector<vector<int>> &dp){
        if(ind == triangle.size()-1){
            return triangle[ind][pos];
        }
        int mini = INT_MAX;
        if(dp[ind][pos] != -1){
            return dp[ind][pos];
        }
        for(int i = 0 ;i <= ind; i++){
            mini = min(mini,triangle[ind][pos] + min(sus(ind+1,pos,triangle,dp),sus(ind+1,pos+1,triangle,dp)));
        }
        return dp[ind][pos] = mini;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return sus(0,0,triangle,dp);
    }
};