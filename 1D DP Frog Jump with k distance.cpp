gfg link : https://practice.geeksforgeeks.org/problems/minimal-cost/1

int t[100002];

class Solution {
    
    private:
    
    int solve(vector<int>&height, int n, int& k){
        
        if(n==0)return 0;
        
        if(t[n]!=-1) return t[n];
        
        int mn = INT_MAX;
        
        for(int i = 1; i<=k; i++){
            
            if(n-i>=0){
                
                int temp = solve(height,n-i,k)+ abs( height[n] - height[n-i]);
                
                mn = min(mn,temp);
            }
            
        }
        
        return t[n] = mn;
    }
    
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        memset(t,-1,sizeof(t));
        
        return solve(height,n-1,k);
    }
};
