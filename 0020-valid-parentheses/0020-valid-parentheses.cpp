class Solution {
public:
    bool isValid(string s) {
        queue <char> q;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                q.push(c);
            }
            else if (c == ')' && q.front() == '(') q.pop();
            else if (c == '}' && q.front() == '{') q.pop();
            else if (c == ']' && q.front() == '[') q.pop();
            else if (c != q.front()) return false;
        }
        if(q.empty()) return true;
        else return false;

    }
};