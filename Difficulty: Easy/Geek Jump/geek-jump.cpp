//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
    int sus(int ind, vector<int>& height,int n,vector<int> &dp){
        if(ind >= n-1){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int forw = abs(height[ind]-height[ind+1]) + sus(ind+1,height,n,dp);
        int next = INT_MAX;
        if(ind+2 <= n-1){
            next = abs(height[ind]-height[ind+2]) + sus(ind+2,height,n,dp);
        }
        return dp[ind] = min(forw,next);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        return sus(0,height,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends