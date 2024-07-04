class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset = 1 << n;
        vector<vector<int>> ans;
        for(int no = 0; no < subset; no ++){
            vector<int> list;
            for(int i =0; i<n;i++){
                if(no &(1 << i)){
                    list.emplace_back(nums[i]);
                }
            }
            ans.emplace_back(list);
        }
        return ans;
    }
};