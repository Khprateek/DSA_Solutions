//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int l =0;
	    int r = n-1;
	    int left  = -1;
	    int right = -1;
	    while(l <= r){
	        int mid = l + (r-l)/2;
	        if(arr[mid] == x){
	            left = mid;
	            r = mid -1;
	        }
	        else if(arr[mid] > x){
	            r = mid -1;
	        }
	        else{
	            l = mid +1;
	        }
	    }
	    l =0;
	    r = n-1;
	    while(l <= r){
	        int mid = l + (r-l)/2;
	        if(arr[mid] == x){
	            right = mid;
	            l = mid + 1;
	        }
	        else if(arr[mid] > x){
	            r = mid -1;
	        }
	        else{
	            l = mid +1;
	        }
	    }
	    
	    if(right != -1 && left != -1){
	        return right - left +1;
	    }
	    else return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends