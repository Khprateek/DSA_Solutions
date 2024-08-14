//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    bool dfs(int start, vector<int>adj[],vector<bool>&vis,vector<bool>&path){
        vis[start] = true;
        path[start] = true;
        
        for(auto it : adj[start]){
            if(!vis[it])
            {
                if(dfs(it,adj,vis,path) == true){
                    return true;
                }
            }
            else if(path[it]){
                return true;
            }
        }
        path[start] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        vector<bool>path(V,false);
        for(int i = 0; i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)==true){
                    return true;
                }
            }
        }
        return false;
        
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends