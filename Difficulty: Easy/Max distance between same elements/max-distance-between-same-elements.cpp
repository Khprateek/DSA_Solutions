//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int,int> dist;
        int maxi = 0;
        for(int i = 0 ;i <n ;i++){
            int val = arr[i];
            if(dist.find(val) != dist.end()){
                maxi = max(maxi,i - dist[val]);
            }
            else{
                dist[val] = i;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends