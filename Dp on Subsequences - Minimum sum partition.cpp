gfg link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution{
    
    private:
    
    int is_subset(int arr[], int n, int sum){
        
        bool t[n+1][sum+1];
        
        for(int i=0;i<sum+1;i++)t[0][i]=false;
        
        for(int i=0;i<n+1;i++)t[i][0]=true;
        
        for(int i=1;i<n+1;i++){
            
            for(int j=1;j<sum+1;j++){
                
                
                if(arr[i-1]<=j){
                    
                    t[i][j] =   t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else t[i][j]    =   t[i-1][j];
            }
        }
        
        vector<int>v;
        
        for(int i=0;i<=sum/2;i++){
            
            if(t[n][i])v.push_back(i);
        }
        
        int mini    =   INT_MAX;
        
        for(int i=0;i<v.size();i++){
            
            mini    =   min(mini, sum - 2*v[i]);
        }
        
        return mini;
        
    }

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int range=0;
	    for(int i=0;i<n;i++)range+=arr[i];
	    
	    
	    return is_subset(arr,n,range);
	    
	} 
};
