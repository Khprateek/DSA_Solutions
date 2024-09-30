//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // vector<int> prev(n+1,-1);
        // vector<int> curr(n+1,-1);
        for(int L = 0; L<= n; L++){
            dp[0][L] = L*price[0];
        }
        for(int ind = 0; ind < n; ind++){
            dp[ind][0] = 0;
        }
        for(int ind = 1; ind< n; ind++){
            for(int L = 0; L<= n; L++){
                int notpick = dp[ind-1][L];
                int pick = 0;
                if(L >= ind+1){
                    pick = price[ind] + dp[ind][L-ind-1];
                }
                dp[ind][L] = max(pick,notpick);
            }
        }
        return dp[n-1][n];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends