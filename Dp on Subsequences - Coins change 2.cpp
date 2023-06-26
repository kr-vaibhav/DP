gfg link : https://practice.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        long long int t[N+1][sum+1];
        
        for(int i=0;i<sum+1;i++)t[0][i]=0;
        
        for(int i=0;i<N+1;i++)t[i][0]=1;
        
        for(int i=1;i<N+1;i++){
            
            for(int j=1;j<sum+1;j++){
                
                if(coins[i-1]<=j){
                    
                    t[i][j] =   t[i][j-coins[i-1]]  +   t[i-1][j];
                }
                else t[i][j]    =   t[i-1][j];
            }
        }
        
        return t[N][sum];
    }
};
