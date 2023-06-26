gfg link : https://practice.geeksforgeeks.org/problems/grid-path-2/1

int t[102][102];

int mod = 1e9+7;

class Solution {
    private:
    
    int solve(int i, int j, int n, int m,  vector<vector<int>>& grid){
        
        if( i>=n || j>=m) return 0;
        
        if( i==n-1 && j==m-1)return 1;
        
        if(grid[i][j]==1)return 0;
        
        if( t[i][j]!=-1) return t[i][j];
        
        int right = solve(i,j+1,n,m,grid)%mod;
        
        int down = solve(i+1,j,n,m,grid)%mod;
        
        return t[i][j] = ( right + down )%mod;
    }
    
    
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        if(grid[n-1][m-1]==1)return 0;
        if(grid[0][0]==1)return 0;
        
        memset(t,-1,sizeof(t));
        
        return solve(0,0,n,m,grid)%mod;
    }
};
