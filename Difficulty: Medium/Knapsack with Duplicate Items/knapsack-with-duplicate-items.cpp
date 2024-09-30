//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
    private:
    int sus(int ind, int val[], int wt[],int W,vector<vector<int>> &dp){
        if(ind < 0) return 0;
        if(ind == 0){
            return (W/wt[0])*val[0];
        }
        if(dp[ind][W] != -1) return dp[ind][W];
        int notpick = sus(ind-1,val,wt,W,dp);
        int pick =0;
        if(W >= wt[ind]){
            pick =val[ind] + sus(ind,val,wt,W-wt[ind],dp);
        }
        return dp[ind][W] = max(pick,notpick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return sus(N-1,val,wt,W,dp);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends