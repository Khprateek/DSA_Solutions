class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> lett(26,0);
        int n1 = ransomNote.length();
        int n2 = magazine.length();
        for(int i = 0; i< n2; i++){
            char c = magazine[i];
            lett[c - 'a']++;
        }
        for(int i =0; i< n1; i++){
            char c = ransomNote[i];
            if(lett[c-'a'] <= 0) return false;
            lett[c-'a']--;
        }
        return true;
    }
};