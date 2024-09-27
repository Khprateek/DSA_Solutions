class Solution {
    private:
    bool sus(int ind,int hand, int left,vector<int> &nums){
        if(hand == left) return true;
        if(ind <= 0) return (hand+nums[ind] == left-nums[ind]);
        bool pick = sus(ind-1,nums[ind]+hand,left-nums[ind],nums);
        bool notpick = sus(ind-1,hand,left,nums);
        return pick | notpick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        for(int i = 0; i< n; i++){
            left += nums[i];
        }
        return sus(n-1,0,left,nums);
    }
};