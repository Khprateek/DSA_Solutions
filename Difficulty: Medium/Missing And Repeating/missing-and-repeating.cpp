//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;
    if(n == 0) return ans;
    
    int X = 0;
    for(int i = 1; i <= n; i++){
        X = X ^ i;
    }
    for(int i = 0; i < n; i++){
        X = X ^ arr[i];
    }
    
    int Y = 0;
    for(int i = 0; i < n; i++){
        Y = Y + arr[i];
    }
    Y = (n*(n+1))/2 - Y;
    
    int set_bit = X & -X;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] & set_bit){
            x = x ^ arr[i];
        } else {
            y = y ^ arr[i];
        }
    }
    for(int i = 1; i <= n; i++){
        if(i & set_bit){
            x = x ^ i;
        } else {
            y = y ^ i;
        }
    }
    
    int missing = 0, repeating = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            repeating = x;
            missing = y;
            break;
        }
        if(arr[i] == y){
            repeating = y;
            missing = x;
            break;
        }
    }
    
    ans.push_back(repeating);
    ans.push_back(missing);
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends