//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i< n+1;i++){
            parent[i] = i;
        }
    }
    int Fup(int node){
        if(parent[node] == node) return node;
        return parent[node] = Fup(parent[node]);
    }
    void Ubs(int u, int v){
        int ulp_u = Fup(u);
        int ulp_v = Fup(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } 
        else{
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        for(int i =0; i< V; i++){
            for(int j =0; j < V; j++){
                if(adj[i][j] == 1){
                    // there is connection b/w i and j
                    ds.Ubs(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i =0; i< V; i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }
        return cnt;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends