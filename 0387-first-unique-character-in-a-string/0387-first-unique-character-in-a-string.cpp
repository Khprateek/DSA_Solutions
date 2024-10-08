class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(26,0);
        int n = s.length();
        for(int i = 0; i < n; i++){
            char c = s[i];
            arr[c-'a']++;
        }
        int l =0;
        while(l < n){
            char c = s[l];
            if(arr[c-'a'] ==1) break;
            l++;
        }
        if(l < n) return l;
        return -1;
    }
};