class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int load =0;
        sort(nums.begin(), nums.end());
        int prev;
        for(int i =1; i< nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                prev = nums[i-1]+1;
                load = load + prev -nums[i];
                nums[i] = prev;
            }
        }
        return load;
    }
};