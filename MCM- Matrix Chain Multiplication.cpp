gfg link : https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication

int t[102][102];

class Solution{
    
    private:
    
    int solve(int arr[], int i, int j){
        
        if(i>=j)return 0;
        
        int mini = INT_MAX;
        
        if(t[i][j]!=-1)return t[i][j];
        
        for(int k = i; k<=j-1; k++){
            
            int left = solve(arr, i, k);
            
            int right = solve(arr, k+1,j);
            
            int cost_lr = arr[i-1]*arr[k]*arr[j];
            
            int temp_cost = left + right + cost_lr;
            
            mini = min( temp_cost, mini);
        }
        
        return  t[i][j] = mini;
    }
    
public:

    Solution(){
        memset(t,-1,sizeof(t));
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr,1,N-1);
    }
};
