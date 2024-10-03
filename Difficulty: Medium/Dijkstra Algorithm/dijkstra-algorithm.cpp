//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V,-1);
        // vector<pair<int,int>> adj[N];
        // for(int i = 0; i< M; i++){
        //     int u = edges[i][0];
        //     int v = edges[i][1];
        //     int wt = edges[i][2];
        //     adj[u].push_back({v,wt});
        // }
        queue<int> q;
        q.push(S);
        dis[S] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                int v = it[0];
                int wt = it[1];
                if(dis[v] == -1){
                    dis[v] = dis[node] + wt;
                    q.push(v);
                }
                else if(dis[node] + wt < dis[v]){
                    dis[v] = dis[node] + wt;
                    q.push(v);
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends