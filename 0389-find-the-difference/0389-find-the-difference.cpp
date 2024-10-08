class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> letters(26,0);
        int n = s.length();
        for(int i= 0; i< n; i++){
            char c = s[i];
            letters[c-'a']++;
        }
        int k = t.length();
        for(int i =0; i< k; i++){
            char c = t[i];
            if(letters[c-'a'] <= 0) return c;
            letters[c-'a']--;
        }
        return -1;
    }
};