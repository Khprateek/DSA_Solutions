class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int z = pow(2,10)-1;
        for(int i =0; i< n; i++){
            nums[i] = nums[i] << 10;
            nums[i] = nums[i] | nums[i+n];
        }
        int j = 2*n -1;
        for(int i = n-1; i >= 0;i--){
            int y = nums[i] & z;
            int x = nums[i] >> 10;
            nums[j] = y;
            nums[j-1] = x;
            j -= 2;
        }
        return nums;
    }
};