gfg link : https://practice.geeksforgeeks.org/problems/edit-distance3702/1

int dp[201][201];

class Solution {
    
    private:
    
    int solve(int i, int j, string s, string t){
        
        if(j<0)return i+1;
        if(i<0)return j+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        if(s[i]==t[j]){
            
            return dp[i][j] = solve(i-1,j-1,s,t);
            
        }
        else{
            
            int insertion = 1 + solve(i,j-1,s,t);
            int deletion = 1 + solve(i-1,j,s,t);
            int replace = 1 + solve(i-1,j-1,s,t);
            
            return dp[i][j] =   min(insertion,min(deletion,replace));
        }
        
    }
    
    
  public:
    int editDistance(string s, string t) {
        // Code here
        
        memset(dp,-1,sizeof(dp));
        
        int n = s.length();
        int m = t.length();
        
        return solve(n-1,m-1,s,t);
    }
};
