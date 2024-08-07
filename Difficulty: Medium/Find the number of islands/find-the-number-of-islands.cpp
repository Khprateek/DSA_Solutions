//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int row,int col,vector<vector<bool>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        
        // first thing to do
        vis[row][col] = true;
        // you also need a queue
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traverse in its neighbour;
            for(int drow = -1; drow <=1;drow++){
                for(int dcol = -1;dcol <=1;dcol ++){
                    int nrow = row+drow;
                    int ncol = col + dcol;
                    if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m){
                        if(grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                            vis[nrow][ncol] = true;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
        
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        for(int row =0; row <n; row++){
            for(int col = 0; col <m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends