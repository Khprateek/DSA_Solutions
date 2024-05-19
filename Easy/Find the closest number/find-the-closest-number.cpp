//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int low =0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]==k){
                return arr[mid];
            }
            else if(arr[mid] < k){
                low = mid + 1;
            }
            else if(arr[mid] > k){
                high = mid -1;
            }
        }
        
        if(abs(arr[low] -k) <= abs(arr[high]-k)) return arr[low];
        else return arr[high];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends