class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 0) return 0;
        int l = 0;
        int r = 0;
        int maxi = 0;
        while(r < n){
            if(nums[r] == 0 && k > 0){
                r++;
                k--;
                maxi = max(maxi,r-l);
            }
            else if(nums[r] == 0 && k <= 0){
                if(nums[l] == 0){
                    l++;
                    k++;
                }
                else if(nums[l] == 1){
                    l++;
                }
            }
            else if(nums[r] == 1){
                r++;
                maxi = max(maxi,r-l);
            }
        }
        return maxi;
    }
};