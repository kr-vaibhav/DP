https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

int t[5005][4];

class Solution {

    private:
    
    int solve(int i, bool bought, int n, vector<int>&prices){
        
        
        if(i>=n)return 0;
        
        if(t[i][bought]!=-1) return t[i][bought];
        
        if(!bought){
            
            int take = -prices[i] + solve(i+1,1,n,prices);
            
            int not_take = solve(i+1,bought, n, prices);
            
            return t[i][bought] = max( take, not_take );
    
        }
        else{
            
            int sell = prices[i] + solve(i+2,0,n,prices);
            
            int not_sell = solve(i+1,1,n,prices);
            
            return t[i][bought] = max( sell, not_sell );
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        
        memset(t,-1,sizeof(t));

        int n = prices.size();

        return solve(0,0,n,prices);
    }
};
