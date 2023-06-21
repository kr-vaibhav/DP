gfg link : https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

int t[1000002];

class Solution{
    
    private:
    
    int solve(int arr[], int i, int n){
        
        if(i>=n)return 0;
        
        if(t[i]!=-1)return t[i];
        
        int mx = INT_MIN;
        
        int take = arr[i] + solve(arr, i+2,n);
        int nottake = solve(arr, i+1,n);
        
        return t[i] = max(take,nottake);
    }
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    memset(t,-1,sizeof(t));
	    
	    return solve(arr,0,n);
	}
};
