//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        for(int i =0;i<n;i++){
            sum += arr[i];
        }
        long long ssum = 0;
        if((sum&1) == 0){
            sum = sum >> 1;
            for(int i = 0; i<n ;i++){
                ssum += arr[i];
                if(ssum > sum){
                    return false;
                }
                else if(ssum == sum){
                    return true;
                }
            }
        }
        else{
            return false;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends