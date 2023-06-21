gfg link: https://practice.geeksforgeeks.org/problems/geeks-training/1

int t[100002][6];

class Solution {
    
    private:
    
    int solve(vector<vector<int>>&points, int row, int dont, int n){
        
        if(row>=n)return 0;
        
        if(t[row][dont]!=-1) return t[row][dont];
        
        int run = INT_MIN ,fight= INT_MIN, learn=INT_MIN;
        
        if(dont!=0) run = points[row][0] + solve(points,row+1,0,n);
        
        if(dont!=1) fight = points[row][1] + solve(points, row+1, 1, n);
        
        if(dont!=2) learn = points[row][2]  + solve(points, row+1, 2, n);
        
        return t[row][dont] =  max( run, max(fight,learn));
    }
    
    
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        memset(t,-1,sizeof(t));
        
        return solve(points,0,5,n);
    }
};
