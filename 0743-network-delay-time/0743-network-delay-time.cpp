class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,1e9);
        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,int>> q;
        q.push({k,0});
        time[k] =0;
        while(!q.empty()){
            int node = q.front().first;
            int late = q.front().second;
            q.pop();
            if(late > time[node]) continue;
            for(auto it : adj[node]){
                int neb = it.first;
                int wt = it.second;
                if(late + wt < time[neb]){
                    time[neb] = late + wt;
                    q.push({neb,time[neb]});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; ++i) {
            if(time[i] == 1e9) return -1;
            maxTime = max(maxTime, time[i]);
        }
        return maxTime;
    }
};