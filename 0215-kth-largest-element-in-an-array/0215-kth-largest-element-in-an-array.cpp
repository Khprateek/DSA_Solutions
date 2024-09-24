class Solution {
    private:
    void Heapify(vector<int> &nums,int i, int N){
        int L = 2*i + 1;
        int R = 2*i + 2;
        int largest = i;
        if(L < N && nums[L] > nums[largest]){
            largest = L;
        }
        if(R < N && nums[R] > nums[largest]){
            largest = R;
        }
        if(largest != i){
            swap(nums[i],nums[largest]);
            Heapify(nums,largest,N);
        }
    }
    void Red(vector<int>& nums,int &N){
        nums[0] = nums[N-1];
        N--;
        Heapify(nums,0,N);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        int internal = (N/2)-1;
        for(int i = internal; i>= 0; i--){
            Heapify(nums,i,N);
        }

        for(int i = 0; i< k-1; i++){
            Red(nums,N);
        }
        return nums[0];

    }
};