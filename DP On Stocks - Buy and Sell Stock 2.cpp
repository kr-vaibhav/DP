https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

int t[3][100000];

class Solution {
    private:
    int solve(bool bought,int i, int n, vector<int>&prices){

        if(i>=n)return 0;

        if(t[bought][i]!=-1)return t[bought][i];

        if(!bought){

            int take = -prices[i] + solve(1,i+1,n,prices);

            int not_take = solve(0,i+1,n,prices);

            return t[bought][i] = max(take , not_take);
        }
        else{

            int sell = prices[i] + solve(0,i+1,n,prices);

            int not_sell = solve(1,i+1,n,prices);

            return t[bought][i] = max( sell,not_sell);
        }
        

    }


public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        memset(t,-1,sizeof(t));

        return solve(0,0,n,prices);
    }
};
