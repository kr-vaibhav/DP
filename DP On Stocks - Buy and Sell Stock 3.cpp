https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/


int t[5][100004];

class Solution {
    private:

    int solve(int i, int times, int n, vector<int>&prices){
    
    if(i>=n){
        
        if(times<=4) return 0;
        
        return -1e6;
    }
    
    if(times > 4) return -1e6;

        if(t[times][i]!=-1)return t[times][i];

        if( times%2 == 0 ){

            int take =  - prices[i] + solve(i+1,times+1,n,prices);

            int not_take = solve(i+1,times,n,prices);

            return t[times][i] = max(take , not_take);
        }
        else{

            int sell = prices[i] + solve(i+1,times+1,n,prices);

            int not_sell = solve(i+1,times,n,prices);

            return t[times][i] =  max( sell,not_sell);
        }
}

public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        memset(t,-1,sizeof(t));

        return solve(0,0,n,prices);
    }
};
