//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    private:
    int jump(int ind,int k, vector<int>& arr,vector<int> &dp){
        int n = arr.size();
        if(ind == n-1) return 0;
        if(ind >= n) return 1e5;
        if(dp[ind] != -1) return dp[ind];
        int mini = INT_MAX;
        for(int i = 1; i<= k; i++){
            mini = min(mini,jump(ind+i,k,arr,dp) + abs(arr[ind] - arr[ind+i]));
        }
        return dp[ind] = mini;
    }
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return jump(0,k,arr,dp);
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends