gfg link : https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1

int t[17][17];

class Solution
{   private:
    
    int solve(int i, int j, int a, int b){
        
        if(i>=a || j>=b) return 0;
        
        if( i== a-1 && j==b-1) return 1;
        
        if(t[i][j]!=-1) return t[i][j];
        
        int down = solve( i + 1, j, a, b) ;
        
        int right = solve( i, j+1, a, b) ;
        
        return t[i][j] =  down + right;
    }
    
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        memset(t,-1,sizeof(t));
        
        return solve(0,0,a,b);
    }
};
