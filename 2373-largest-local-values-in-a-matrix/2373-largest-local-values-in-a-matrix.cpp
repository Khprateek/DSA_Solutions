class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans;
        int maxi =0;
        for(int i = 1; i < n-1; i++){
        vector<int> rowlis;
            for(int j = 1; j< n-1; j ++){
                for(int r =1; r >=-1; r--){
                    for(int c =1 ;c >= -1; c--){
                        maxi = max(maxi,grid[i+r][j+c]);
                    }
                }
                rowlis.emplace_back(maxi);
                maxi =0;
            }
            ans.emplace_back(rowlis);
        }
        return ans;
    }
};