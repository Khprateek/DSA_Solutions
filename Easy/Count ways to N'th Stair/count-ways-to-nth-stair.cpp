//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        if(n == 0) return 1;
        else if (n == 1) return 1;
        int prev1 = 1;
        int prev = 1;
        int ans;
        for(int i =2; i <= n ; i++){
            ans = prev1 + 1;
            prev1 = prev;
            prev = ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends