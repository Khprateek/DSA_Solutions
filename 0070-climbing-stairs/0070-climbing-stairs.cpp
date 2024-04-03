class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        else if(n==2) return 2;
        int prev1 = 1;
        int prev = 2;
        int ans;
        for(int i = 3 ; i<=n ; i++){
            ans = prev1 + prev;
            prev1 = prev;
            prev = ans;
        }
        return ans;
    }
};