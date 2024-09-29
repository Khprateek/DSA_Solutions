class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        if(n==0){
            return {-1,-1};
        }
        int l = 0;
        int r = n-1;
        int first = -1;
        int second = -1;
        // first finding the first position of the element;
        int mid = l + (r-l)/2;
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] == target){
                first = mid;
                r = mid-1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        l = 0;
        r = n-1;

        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] == target){
                second = mid;
                l = mid+1;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return {first,second};
    }
};