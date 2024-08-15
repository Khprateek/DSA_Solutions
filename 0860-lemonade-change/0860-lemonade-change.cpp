class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int f =0;
        int t =0;
        for(int i =0; i<n; i++){
            if(bills[i] == 5) f++;
            if(bills[i] == 10){
                if(f!=0){
                    f--;
                    t++;
                }
                else{
                    return false;
                }
            }
            if(bills[i] == 20){
                if(t!=0 && f!=0){
                    t--;
                    f--;
                }
                else if(f >=3){
                    f -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};