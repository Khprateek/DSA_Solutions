class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        if(n==1) return 1;
        int l = 0;
        int r = 0;
        vector<int> a(500,0);
        int cnt = 0;
        int ans = INT_MIN;
        while(r < n && l < n){
            if(a[s[r]] == 0){
                a[s[r]] =1;
                r++;
                cnt++;
                ans = max(ans,cnt);
            }
            else{
                while(a[s[r]] != 0){
                    a[s[l]] = 0;
                    l++;
                    cnt--;
                }
            }
        }
        return ans;

    }
};