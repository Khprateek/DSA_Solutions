//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
    if (arr.empty() || x < 0) return -1;

    sort(arr.begin() , arr.end());
    int low = 0;
    int high = 1; // Start with adjacent elements

    while (high < n) {
        if (low >= n || high < 0) return -1; // Check for out-of-bounds access
        int diff = arr[high] - arr[low];
        if (diff == x) return 1;
        else if (diff < x) high++;
        else low++;
        if (low == high) high++; // Move high pointer if low and high are the same
    }
    return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends