class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int remain =1;
        int i = digits.size()-1;
        while(i >= 0){
            int addup = digits[i] + remain;
            int curr = addup%10;
            remain = addup/10;
            ans.push_back(curr);
            i--;
        }
        if(remain > 0){
            ans.push_back(remain);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};