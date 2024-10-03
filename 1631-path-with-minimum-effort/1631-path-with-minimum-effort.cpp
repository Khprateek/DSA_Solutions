class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> diff(n,vector<int> (m,1e9));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        diff[0][0] = 0;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int effort = q.front().first;
            q.pop();
            for(int i = 0; i< 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                int neffort =max(effort,abs(heights[r][c] - heights[nr][nc]));
                    if(neffort < diff[nr][nc]){
                        diff[nr][nc] = neffort;
                        q.push({neffort,{nr,nc}});
                    }
                }
            }
        }
        return diff[n-1][m-1];
    }
};