gfg link : https://practice.geeksforgeeks.org/problems/target-sum-1626326450/1

class Solution {
  public:
    int findTargetSumWays(vector<int>&nums ,int target) {
        //Your code here
        int n   =   nums.size();

        int mod=1e9+7;

        int range=0;
        for(int i=0;i<n;i++)range+=nums[i];

        if( (range-target)<0 || (range+target)<0 || ((range+target)%2)!=0 ) return 0;



        int sum =   ((range+target)/2)%mod;

        vector<vector<int>>t(n+1,vector<int>(sum+1,0));

        t[0][0] =   1;

        for(int i   =   1;i<n+1;i++){

            for(int j=0; j<sum+1;j++){


                if(nums[i-1]<=j){

                    t[i][j] =   ( t[i-1][j-nums[i-1]] + t[i-1][j] )%mod;
                }
                else t[i][j]    =   t[i-1][j]%mod;
            }
        }
        

        return t[n][sum] % mod;
    }
};
