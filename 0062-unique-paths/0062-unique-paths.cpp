class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        prev[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 1; j< n;j++){
                prev[j] += prev[j-1];
            }
        }
        return prev[n-1];
    }
};