leetcode link : https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int V) {
        
        int M   =   coins.size();

        int t[M+1][V+1];
	    
	    
	    for(int i=0;i<M+1;i++)t[i][0]=0;
	    for(int i=0;i<V+1;i++)t[0][i]=INT_MAX-1;

	    
	    for(int i=1;i<M+1;i++){
	        
	        for(int j=1;j<V+1;j++){
	            
	            if(coins[i-1]<=j){
	                
	                t[i][j] =   min( 1+t[i][j-coins[i-1]], t[i-1][j]);
	            }
	            else t[i][j] = t[i-1][j];
	        }
	    }
	    
	    if(t[M][V]==INT_MAX -1)return -1;
	    return t[M][V];
    }
};
