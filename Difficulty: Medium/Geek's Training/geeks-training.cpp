//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        if(n == 0) return 0;
        if(n == 1){
            return max(arr[0][0],max(arr[0][1],arr[1][2]));
        }
        int prev0 =0;
        int prev1 =0;
        int prev2 =0;
        int prev3 =0;
        for(int ind =0;ind < n; ind++){
            int curr0 =arr[ind][0] + max(prev1,prev2);
            int curr1 =arr[ind][1] + max(prev0,prev2);
            int curr2 =arr[ind][2] + max(prev0,prev1);
            prev0 = curr0;
            prev1 = curr1;
            prev2 = curr2;
        }
        return max(prev0,max(prev1,prev2));
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
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends