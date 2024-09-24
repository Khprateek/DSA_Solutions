//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void Maxify(vector<int> &arr, int i, int N){
        int L = 2*i + 1;
        int R = 2*i + 2;
        int Largest = i;
        if(L < N && arr[L] > arr[i]){
            Largest = L;
        }
        if(R < N && arr[R] > arr[Largest]){
            Largest = R;
        }
        if(Largest != i){
            swap(arr[i],arr[Largest]);
            Maxify(arr,Largest,N);
        }
    }
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        int inter = (N/2)-1;
        for(int i = inter; i >= 0; i--){
            Maxify(arr, i,N);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends