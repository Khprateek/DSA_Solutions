class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        int dr[] = {-1,-1,-1,0,1,1,1,0};
        int dc[] = {-1,0,1,1,1,0,-1,-1};
        q.push({1,{0,0}});
        dist[0][0] =1;

        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int dis = q.front().first;
            q.pop();

            if(r == n-1 & c == n-1) return dis;

            for(int i = 0; i< 8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >=0 && nr <n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                    if(dis + 1 < dist[nr][nc]){
                        dist[nr][nc] = dis +1;
                        q.push({dis+1,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};