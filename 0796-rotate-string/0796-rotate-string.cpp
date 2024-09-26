class Solution {
    private:
    void next(string &s){
        char c = s[0];
        int n = s.length();
        s = s.substr(1,n-1) + c;
    }
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
        for(int i = 0; i < n; i++){
            if(s == goal){
                return true;
            }
            next(s);
        }
        return false;
    }
};