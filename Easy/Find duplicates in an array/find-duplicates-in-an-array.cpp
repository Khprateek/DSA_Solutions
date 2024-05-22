//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
  public:
    vector<int> duplicates(long long arr[], int n) {
        
        vector<int> ans;
        vector<int> vis(n ,0);
        
        
        for(int i =0; i< n; i++){
            vis[arr[i]]++;
        }
        for(int i =0; i< n; i++){
            if(vis[i] >1){
                ans.push_back(i);
            }
        }
        if(!ans.empty()){
            return ans;
        }
        else return {-1};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends