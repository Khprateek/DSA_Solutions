class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        int maxi = INT_MIN;
        if(k >= n){
            for(int i =0; i< n; i++){
                ans += cardPoints[i];
            }
            return ans;
        }
        else{
            for(int i =0; i< k ; i++){
                ans += cardPoints[i];
                maxi = max(maxi,ans);
            }
        }
        int l = k-1;
        int r = n-1;
        while(l >= 0){
            ans -= cardPoints[l];
            ans += cardPoints[r];
            l--;
            r--;
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};