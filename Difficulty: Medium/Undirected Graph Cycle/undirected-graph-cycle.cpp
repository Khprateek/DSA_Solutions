//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    private:
    bool dfs(int node, int parent,vector<int> adj[], vector<bool> &vis){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, node,adj,vis) == true) return true; 
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        
        for(int i = 0 ;i < V; i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis) == true) return true;
            }
        }
        return false;
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends