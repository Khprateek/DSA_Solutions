//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.

class Solution{
    public:
    long long maximumAmount(int n, int arr[]){
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Base cases: when i == j, dp[i][j] is simply the value at index i
        for (int i = 0; i < n; ++i)
            dp[i][i] = arr[i];

        // Fill the dp table diagonally
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                // If we pick arr[i], the opponent can choose between arr[i+1] and arr[j]
                long long pickLeft = arr[i] + min((i + 2 <= j ? dp[i + 2][j] : 0), (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
                // If we pick arr[j], the opponent can choose between arr[i] and arr[j-1]
                long long pickRight = arr[j] + min((i <= j - 2 ? dp[i][j - 2] : 0), (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
                dp[i][j] = max(pickLeft, pickRight);
            }
        }

        // The maximum amount is stored at dp[0][n-1]
        return dp[0][n - 1];
    }
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends