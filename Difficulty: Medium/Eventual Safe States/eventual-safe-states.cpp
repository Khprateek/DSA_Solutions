//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfs(int node,vector<int> adj[],vector<bool> &vis,vector<bool> &pathvis, int check[]){
        vis[node] = true;
        pathvis[node] = true;
        check[node] = 0;
        
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj, vis, pathvis, check) == true){
                    check[node] =0;
                    return true;
                }
            }
            else if(pathvis[it]){
                check[node] = 0;
                return true;
            }
        }
        
        check[node] =1;
        pathvis[node] = 0;
        return false;;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        vector<bool> pathvis(V,false);
        vector<int> safenode;
        int check[V] = {0};
        for(int i =0; i<V;i++){
            if(!vis[i]){
                dfs(i, adj, vis,pathvis, check);
            }
        }
        for(int i =0; i<V; i++){
            if(check[i] == 1){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends