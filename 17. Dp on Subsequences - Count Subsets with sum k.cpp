gfg link : https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution{
    
    private: 
    
    int zeros_till_index(int arr[], int i){
        
        int count=0;
        for(int j=0;j<=i;j++){
            
            if(arr[j]==0)count++;
        }
        
        return count;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        long long t[n+1][sum+1];
        long long mod=1e9+7;
        
        
        for(int i=0;i<sum+1;i++)t[0][i]=0;
        
        for(int i=0;i<n+1;i++)t[i][0]=pow(2,zeros_till_index(arr,i));
        
        
        for(int i=1;i<n+1;i++){
            
            
            for(int j=1;j<sum+1;j++){
                
                if(arr[i-1]<=j){
                    
                    t[i][j] =  ( t[i-1][j-arr[i-1]] + t[i-1][j] )%mod;
                }
                else t[i][j]    =   t[i-1][j]%mod;
            }
        }
        
        t[n][sum]   =   (t[n][sum]*zero)%mod;
        
        return t[n][sum];
        
        
	}
	  
};
