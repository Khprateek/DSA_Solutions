class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        string a1 (256,'\0');
        string a2 (256,'\0');

        int n = s.length();
        if(n != t.length()){
            return false;
        }
        for(int i =0; i<n ;i++){
            if(a1[s[i]] != '\0' && a1[s[i]] != t[i]){
                return false;
            }
            if(a2[t[i]] != '\0' && a2[t[i]] != s[i]){
                return false;
            }
            else{
                a1[s[i]] = t[i];
                a2[t[i]] = s[i];
            }
        }
        return true;
    }
};