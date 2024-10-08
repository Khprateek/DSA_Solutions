class DisjointSet {
    vector<int> parrent, size;
public:
    DisjointSet(int n) {
        parrent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parrent[i] = i;
        }
    }
    int FindP(int x) {
        if (parrent[x] == x)
            return x;
        return parrent[x] = FindP(parrent[x]);
    }
    void MkUnion(int u, int v) { 
        int ulp_u = FindP(u);
        int ulp_v = FindP(v);
        if(ulp_u == ulp_v) return ;
        if(size[ulp_u] < size[ulp_v]){
            size[ulp_v] += size[ulp_u];
            parrent[ulp_u] = ulp_v;
        }
        else{
            size[ulp_u] += size[ulp_v];
            parrent[ulp_v] = ulp_u;
        }
    }
    int countp(){
        int cnt = 0;
        for(int i = 0; i< parrent.size();i++){
            if(FindP(i) == i){
                cnt++;
            }
        }
        return cnt;
    }
} ;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        DisjointSet ds(v);
        for(int i = 0; i< v; i++){
            for(int j = 0; j <v; j++){
                if(isConnected[i][j] == 1){
                    ds.MkUnion(i,j);
                }
            }
        }
        int cnt = ds.countp();
        return cnt;
    }
};