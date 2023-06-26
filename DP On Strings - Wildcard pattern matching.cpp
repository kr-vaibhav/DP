gfg link : https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

int t[202][202];

class Solution{
    private:
    
    bool solve(int i, int j, string str, string ptr){
        
       if(i<0 && j<0)return true;
       if(j<0 && i>=0)return false;
       
       if(j>=0 && i<0){
           
           
           for(int k = 0;k<=j ;k++){
               
               if(ptr[k]!='*'){
                   return false;
               }
           }
           
           return true;
       }
       
       if(t[i][j]!=-1) return t[i][j];
       
       if(ptr[j]=='?' || str[i]==ptr[j]){
           
           return  t[i][j] = solve(i-1,j-1,str,ptr);
       } 
       
       if( ptr[j]=='*'){
           
           return t[i][j] = solve(i,j-1,str,ptr) || solve(i-1,j,str,ptr);
       }
       
            return t[i][j] = false;
       
    }
    
    
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        memset(t,-1,sizeof(t));
        
        int n = str.length();
        int m = pattern.length();
        
        return solve(n-1,m-1,str,pattern);
    }
};
