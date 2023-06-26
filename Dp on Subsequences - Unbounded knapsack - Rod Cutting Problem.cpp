gfg link : https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int length[n];
        
        for(int i=0;i<n;i++)length[i]=i+1;
        
        vector<vector<int>>t(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<n+1;i++){
            
            for(int j=1;j<n+1;j++){
                
                if(length[i-1]<=j){
                    
                    t[i][j] =   max( price[i-1]+t[i][j-length[i-1]], t[i-1][j]);
                }
                else{
                    
                    t[i][j] =   t[i-1][j];
                    
                }
            }
        }
        
        return t[n][n];
    }
};
