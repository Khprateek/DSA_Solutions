//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int subArraySum(vector<int>& arr, int tar) {
        int ans = 0;
        int sum = 0;
        map<int, int> mp;
        mp[0]++;
        for(auto it: arr) {
            sum+=it;
            mp[sum]++;
            int x = sum-tar;
            if(mp.find(x) !=mp.end()) ans+= mp[x];
        }
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends