//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int sus(int ind, int last, vector<vector<int>>& arr,vector<vector<int>> &dp){
        if(ind < 0) return 0;
        if(dp[ind][last] != -1) return dp[ind][last];
        int maxi = 0;
        for(int i =0 ;i <3; i++){
            if(i != last ){
                int coin = arr[ind][i] + sus(ind-1,i,arr,dp);
                maxi = max(maxi,coin);
            }
        }
        return dp[ind][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return sus(n-1,3,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends