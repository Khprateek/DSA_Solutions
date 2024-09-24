//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    private:
    void Heapify(vector<int> & arr,int i, int N){
        int L = 2*i+1;
        int R = 2*i+2;
        int smallest = i;
        if(L < N && arr[L] < arr[smallest]){
            smallest = L;
        }
        if(R < N && arr[R] < arr[smallest]){
            smallest = R;
        }
        if(smallest != i){
            swap(arr[i],arr[smallest]);
            Heapify(arr,smallest,N);
        }
    }
    void reduce(vector<int> & arr, int &N){
        swap(arr[0],arr[N-1]);
        N--;
        Heapify(arr,0,N);
    }
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        int N = arr.size();
        int internal = (N/2)-1;
        for(int i = internal; i>=0; i--){
            Heapify(arr,i,N);
        }
        for(int i = 0; i< k-1;i++){
            reduce(arr,N);
        }
        return arr[0];
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends