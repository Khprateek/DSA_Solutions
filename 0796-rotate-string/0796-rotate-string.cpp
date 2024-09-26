class Solution {
public:
    bool rotateString(string s, string goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = s.length();
        if(n != goal.length()){
            return false;
        }
        if(n ==0 ){
            return true;
        }
        s = s + s;
        for(int i = n-1; i >= 0; i--){
            if(s.substr(i,n) == goal){
                return true;
            }
        }
        return false;
    }
};