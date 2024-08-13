//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int d =0;
        for(int i= 0;i <n;i++){
            for(int j=0; j< m; j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},d});
                    vis[i][j] =true;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            d = q.front().second;
            q.pop();
            ans[x][y] = d;
            int a[]= {-1,0,1,0};
            int b[]= {0,1,0,-1};
            for(int i = 0; i< 4; i++){
                int r = x + a[i];
                int c = y + b[i];
                if(r >= 0 && r < n && c >= 0 && c < m && vis[r][c] == false){
                    vis[r][c] = true;
                    q.push({{r,c},d+1});
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends