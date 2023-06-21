gfg link : https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution{
    public:

    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int t[n+1][m+1];
        
        for(int i=0;i<n+1;i++)t[i][0]=0;
        for(int j=0;j<m+1;j++)t[0][j]=0;
        
        for(int i=1;i<n+1;i++){
            
            for(int j=1;j<m+1;j++){
                
                
                if(s1[i-1] == s2[j-1]){
                    
                    t[i][j] =   1 + t[i-1][j-1];
                }
                else {
                    
                    t[i][j] =   0;
                }
            }
        }
        
        int maxi=INT_MIN;
        
        for(int i=0;i<n+1;i++){
            
            for(int j=0;j<m+1;j++){
                
                maxi    =   max(maxi,t[i][j]);
            }
        }
        
        return maxi;
    }
};
