//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution {
//     private:
//     bool dfs(int start, vector<int>adj[],vector<bool>&vis,vector<bool>&path){
//         vis[start] = true;
//         path[start] = true;
        
//         for(auto it : adj[start]){
//             if(!vis[it])
//             {
//                 if(dfs(it,adj,vis,path) == true){
//                     return true;
//                 }
//             }
//             else if(path[it]){
//                 return true;
//             }
//         }
//         path[start] = false;
//         return false;
//     }
//   public:
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<int> adj[]) {
//         vector<bool>vis(V,false);
//         vector<bool>path(V,false);
//         for(int i = 0; i<V;i++){
//             if(!vis[i]){
//                 if(dfs(i,adj,vis,path)==true){
//                     return true;
//                 }
//             }
//         }
//         return false;
        
//     }
// };


// Khans algorithm

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // create the indegree vector
        vector<int> indeg(V,0);
        queue<int> q;
        
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        
        
        for(int i = 0; i< V;i++){
            if(indeg[i] ==0){
                q.push(i);
            }
        }
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        if(cnt == V) return false;
        return true;
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