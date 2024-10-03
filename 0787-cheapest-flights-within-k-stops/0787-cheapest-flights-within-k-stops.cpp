class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it :flights){
            int f = it[0];
            int t = it[1];
            int p = it[2];
            adj[f].push_back({t,p});
        }
        vector<int> cost(n,1e9);
        queue<tuple<int,int,int>> q;
        q.push({0,src,0});
        while(!q.empty()){
            auto [c,u,stops] = q.front();
            q.pop();
            if(stops > k) continue;
            for(auto it : adj[u]){
                int ncost = c + it.second;
                if(ncost < cost[it.first]){
                    cost[it.first] = ncost;
                    q.push({ncost,it.first,stops+1});
                }
            }
        }
        return cost[dst];
    }
};