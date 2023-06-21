gfg link : https://practice.geeksforgeeks.org/problems/geek-jump/1

int t[100002];

class Solution {
    
    private:
    
    int solve(vector<int>&height, int n){
        
        if(n==0)return 0;
        
        if(t[n]!=-1) return t[n];
        
        int one = solve(height,n-1) + abs( height[n] - height[n-1]);
        
        int two = INT_MAX;
        
        if(n>1) two = solve(height,n-2) + abs( height[n] - height[n-2]);
        
        return t[n] = min(one, two);
    }
    
    
    
  public:
  
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        memset(t,-1,sizeof(t));
        
        return solve(height,n-1);
    }
};
