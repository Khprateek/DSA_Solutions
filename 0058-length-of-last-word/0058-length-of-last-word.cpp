class Solution {
public:
    int lengthOfLastWord(string s) {
        int length =0;
        bool found = false;
        for(int i=0; i < s.length(); i++){
            if(s[i] != ' '){
                if(!found){
                    length =1;
                    found = true;
                }
                else{
                    length++;
                }
            }
            else{
                found = false;
            }
        }
        
        return length;
    }
};