gfg link : https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int t[x+1][y+1];
        
        
        //for(int i=0;i<x+1;i++)t[i][0]=0;
        //for(int i=0;i<y+1;i++)t[0][i]=0;
        
        
        memset(t,0,sizeof(t));
        
        
        for(int i=1;i<x+1;i++){
            
            for(int j=1;j<y+1;j++){
                
                if( s1[i-1] == s2[j-1]){
                    
                    t[i][j] =  1 + t[i-1][j-1];
                   
                }
                else{
                    
                    t[i][j] =   max(t[i-1][j], t[i][j-1]);
                }
            }
        }
    
        
        return t[x][y];
    }
};
