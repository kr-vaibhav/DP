gfg link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int t[N+1][W+1];
        
        memset(t,0,sizeof(t));
        
        for(int i=1;i<N+1;i++){
            
            for(int j=1;j<W+1;j++){
                
                if(wt[i-1]<=j){
                    
                    t[i][j] = max(  val[i-1]  +  t[i][j-wt[i-1]],  t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[N][W];
    }
};
