class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();
        for(int i =0; i< n; i++){
            for(char it : words[i]){
                if(it == x){
                    ans.emplace_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};