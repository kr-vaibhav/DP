gfg link : https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1

class Solution{
  public:
    int countMin(string A){
    //complete the function here
        string B(A);
        reverse(B.begin(),B.end());
        
        int n   =   A.length();
        
        int t[n+1][n+1];
        
        for(int i=0;i<n+1;i++){
            
            t[i][0] = 0;
            t[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++){
            
            for(int j=1;j<n+1;j++){
                
                if(A[i-1]==B[j-1]){
                    
                    t[i][j] =  1 + t[i-1][j-1];
                }
                else{
                    
                    t[i][j] = max( t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        if(t[n][n]==n)return 0;
        
        return n-t[n][n];
    }
};
