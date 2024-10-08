class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i =0, j = 1;
        while(j < nums.size()){
            if(nums[i] == nums[j]){
                return true;
            }
            else{
                if(abs(j-i) < k){
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        return false;
    }
};