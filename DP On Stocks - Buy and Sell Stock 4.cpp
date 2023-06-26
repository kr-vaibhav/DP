https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

int t[208][1004];

class Solution {
    private:

    int solve(int i, int times, int n, int k,  vector<int>& prices){
    
    if(i>=n){
        
        if(times/2<=k) return 0;
        
        return -1e6;
    }
    
    if(times/2 > k) return -1e6;

        if(t[times][i]!=-1)return t[times][i];

        if( times%2 == 0 ){

            int take =  - prices[i] + solve(i+1,times+1,n,k,prices);

            int not_take = solve(i+1,times,n,k,prices);

            return t[times][i] = max(take , not_take);
        }
        else{

            int sell = prices[i] + solve(i+1,times+1,n,k,prices);

            int not_sell = solve(i+1,times,n,k,prices);

            return t[times][i] =  max( sell,not_sell);
        }
}

public:
    int maxProfit(int k, vector<int>& prices) {
        
        memset(t,-1,sizeof(t));

        int n = prices.size();

        return solve(0,0,n,k,prices);
    }
};
