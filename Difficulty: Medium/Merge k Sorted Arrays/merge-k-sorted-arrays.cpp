//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

// THIS IS THE PRIORITY QUEUE APPROACH:::::::::::

class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        
        vector<int> ans;
        if(K == 0) return ans;
        if(K == 1){
            
            return arr[0];
        }
        
        // priority_queue<int,pair<int,int>> pq;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i <K; i++){
            pq.push({arr[i][0],{i,0}});
        }
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            ans.push_back(node.first);
            if(node.second.first < K && node.second.second < K-1) {
                pq.push({arr[node.second.first][node.second.second+1],{node.second.first,node.second.second+1}});
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends