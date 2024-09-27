//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
    private:
    
    int mod = 1e9 + 7;
    int sus(int ind,int arr[], int n, int sum,vector<vector<int>> &dp){
        if(ind < 0) return (sum == 0);
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int notpick = sus(ind-1,arr,n,sum,dp);
        int pick = 0;
        if (arr[ind] <= sum) {
            pick = sus(ind - 1, arr, n, sum - arr[ind],dp);
        }
        return dp[ind][sum] = (pick + notpick)%mod;
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return sus(n-1,arr,n,sum,dp);
	}
	  
};



//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends