https://practice.geeksforgeeks.org/problems/number-of-longest-increasing-subsequence/1

class  Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here

        vector<int>dp(n,1), count(n,1);

        int mx = 1;

        for(int i=0;i<n;i++){
            
            for(int prev = 0; prev<i;prev++){
                
                if(arr[prev] < arr[i] && dp[prev] + 1 > dp[i] ){
                    
                    dp[i] = dp[prev] + 1;
                    count[i] = count[prev];
                }
                else if( arr[prev] < arr[i] && dp[prev] +1 == dp[i] ){

                    count[i] += count[prev];
                }
            }

            mx = max(mx,dp[i]);
           
        }
        
        int no = 0;
        for(int i=0;i<n;i++){

            if(dp[i]==mx){

                no += count[i];
            }
        }
        
        return no;
    }
};
