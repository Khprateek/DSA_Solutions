class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int n = num.size();
        int i = n-1;
        while(i >= 0){
            while(i >= 0 && (num[i]-'0')%2 == 0){
                i--;
            }
            if(i < 0){
                return ans;
            }
            ans = num.substr(0,i+1);
            break;
        }
        return ans;
    }
};