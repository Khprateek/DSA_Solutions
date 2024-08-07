//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    void dfs(int row,int col,vector<vector<int>>&image, 
    vector<vector<int>> &ans,int newColor, int drow[], int dcol[],int tcolor){
        int n = image.size();
        int m = image[0].size();
        
        ans[row][col] = newColor;
        for(int i =0; i< 4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
                if(image[nrow][ncol] == tcolor && ans[nrow][ncol] != newColor) {
                    dfs(nrow,ncol,image,ans,newColor,drow,dcol,tcolor);
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int tcolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int drow[] ={-1,0,1,0};
        int dcol[] ={0,1,0,-1};
        if(tcolor != newColor){
            dfs(sr,sc,image,ans,newColor,drow,dcol,tcolor);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends