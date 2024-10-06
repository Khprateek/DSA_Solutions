//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
  vector<int> size,parent;
  public:
  DisjointSet(int n){
      size.resize(n+1,1);//for both 1 based and 0 based.
      parent.resize(n+1);
      for(int i = 0; i< n+1;i++){
          parent[i] = i;
      }
  }
  int FuP(int node){
      if(parent[node] == node) return node;
      return parent[node] = FuP(parent[node]);
  }
  void UbS(int u, int v){
      int ulp_u = FuP(u);
      int ulp_v = FuP(v);
      if(ulp_u == ulp_v) return;
      if(size[ulp_u] < size[ulp_v]){
          size[ulp_v] += size[ulp_u];
          parent[ulp_u] = parent[ulp_v];
      }
      else{
          size[ulp_u] += size[ulp_v];
          parent[ulp_v] = parent[ulp_u];
      }
  }
};
class Solution
{
	public:
    int spanningTree(int V, vector<pair<int,pair<int,int>>> adj)
    {
        DisjointSet ds(V);
        sort(adj.begin(),adj.end());
        int mst = 0;
        for(auto it : adj){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.FuP(u) != ds.FuP(v)){
                mst += wt;
                ds.UbS(u,v);
            }
        }
        return mst;
    }
    
};
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,pair<int,int>>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            adj.push_back({w,{u,v}});
        }
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
