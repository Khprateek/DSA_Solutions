class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.length();
        string ans = "";
        while(i < n){
            while(s[i] == ' '){
                i++;
            }
            if(i >= n) break;
            int j = i;
            while(j < n && s[j] != ' '){
                j++;
            }
            if(ans != ""){
                ans = s.substr(i,j-i) + " " + ans;
                i = j;
            }
            else{
                ans += s.substr(i,j-i);
                i = j;
            }
        }
        return ans;
    }
};