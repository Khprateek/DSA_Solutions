class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = s.length();
        if(n != t.length()){
            return false;
        }
        vector<int> a(26,0);

        for(int i = 0 ; i<n; i++){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        for(int i = 0 ; i<26; i++){
            if(a[i] != 0){
                return false;
            }
        }
        return true;
    }
};