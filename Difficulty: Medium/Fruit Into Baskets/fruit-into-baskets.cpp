//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n = arr.size();
        if(n < 2) return n;
        int l =0;
        int r =1;
        int f1 = arr[0];
        int f2 = arr[1];
        int maxi = 0;
        while(r < n-1){
            if(arr[r+1] != f1 && arr[r+1] != f2){
                f1 = arr[r];
                f2 = arr[r+1];
                l = r;
                while(l > 0 && arr[l] == arr[l-1]){
                    l--;
                }
                r++;
                maxi = max(maxi,r-l);
            }
            else{
                r++;
                maxi = max(maxi,r-l);
            }
        }
        return maxi+1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends