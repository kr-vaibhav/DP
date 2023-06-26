gfg link : https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1


int t[1002][1002];

class Solution{
    private:
    
    int solve(int i, int j, int n, vector<vector<int>>& matrix ){
        
        if( i>= n || j<0 || j>=n)return -1e5;
        
        if(i == n-1) return matrix[i][j];
        
        if(t[i][j]!=-1) return t[i][j];
        
        int mx = INT_MIN;
            
            int d = solve(i+1,j,n,matrix) + matrix[i][j];
            
            int dl = solve(i+1,j-1,n,matrix) + matrix[i][j];
            
            int dr = solve(i+1,j+1,n,matrix) + matrix[i][j];
            
            int temp = max(d,max(dl,dr));

            mx = max(mx,temp);
        
 
        
        return t[i][j] = mx;
    }
    
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        
        memset(t,-1,sizeof(t));
        int n = Matrix.size();

        int mx = INT_MIN;

        for(int col =0 ; col<n ; col++){

            mx = max(mx,solve(0,col,n,Matrix));
        }

        return mx;
        
        
    }
};
