https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int mx = -1e7;

        for(int i=0;i<n;i++){

            int take = prices[i];
            int temp;
            
            for( int j=i+1;j<n;j++){

                if(prices[j]-take > 0){

                    mx = max( mx, prices[j]-take);
                }
            } 
        }

        if(mx!=-1e7)return mx;
        return 0;
    }
};
