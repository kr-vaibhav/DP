gfg link : https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        
        int t[m+1][n+1];
        
        for(int i=0;i<m+1;i++)t[i][0]=0;
        for(int i=0;i<n+1;i++)t[0][i]=0;
        
        for(int i=1;i<m+1;i++){
            
            for(int j=1;j<n+1;j++){
                
                if(X[i-1]==Y[j-1]){
                    
                    t[i][j] =   1 + t[i-1][j-1];

                }
                else{
                    
                    t[i][j] =   max( t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        
        
        return m+n-t[m][n];
        
    }
};
