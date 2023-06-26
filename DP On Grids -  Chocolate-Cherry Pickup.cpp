gfg link : https://practice.geeksforgeeks.org/problems/chocolates-pickup/1

int t[201][201][201];

class Solution {
    private:
    
    int find( int r, int c1, int c2, int n, int m, vector<vector<int>>& grid){
        
        
        if( c1 < 0 || c1 >= m ||  c2<0 || c2>=m)return -1e7;
        
        if(r==n-1){
            
            if(c1!=c2) return grid[r][c1]+grid[r][c2];
            
            else return grid[r][c1];
        }
        
        if(t[r][c1][c2]!=-1) return t[r][c1][c2];
        
        int mx = INT_MIN;
        
        int delcol[3] = {-1,0,+1};
        
        for(int del1 = -1 ; del1<=1; del1++){
            
            for(int del2 = -1; del2<=1; del2++){
                
                int temp;
                
                if(c1!=c2){
                    
                    temp = find(r+1,c1+del1,c2+del2,n,m,grid) + grid[r][c1] + grid[r][c2] ;
                    
                    
                }
                else{
                    
                    temp = find(r+1,c1+del1,c2+del2,n,m,grid) + grid[r][c1] ;
                }
                
                mx = max(mx,temp);
            }
        }
        
        
        
        return t[r][c1][c2] = mx;
    }
    
    
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        memset(t,-1,sizeof(t));
        
        return find(0,0,m-1,n,m,grid);
    }
};
