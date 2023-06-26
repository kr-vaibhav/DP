gfg link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution{
    
    private:
    
    bool isSubsetSum(int arr[], int sum, int n){
        // code here 
        
        bool t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            
            for(int j=0;j<sum+1;j++){
                
                if(i==0)t[i][j]=false;
                
                if(j==0)t[i][j]=true;
            }
        }
        
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=sum;j++){
                
                
                if(arr[i-1]<=j){
                    
                    t[i][j]     =   t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else t[i][j]    =   t[i-1][j];
            }
        }
        
        return t[n][sum];
        
    }
    
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        long long sum=0;
        
        for(long long i=0;i<n;i++)sum+=arr[i];
        
        if(sum%2!=0)return 0;
        
        return isSubsetSum(arr,sum/2,n);
    }
};
