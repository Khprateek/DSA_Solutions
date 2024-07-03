class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int i =0;
        for(int i =0; i< command.size(); i++){
            if(command[i] == 'G'){
            ans += "G";
           }
           else if(command[i] == '(' && command[i+1] == ')'){
            ans += "o";
           }
           else if(command[i] == 'a'){
            ans += "al";
           }
        }
        return ans;
    }
};