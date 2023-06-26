https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    
	    vector<int>dp(n,1),dp1(n,1);
	    
	    int mid = n/2;
	    
	    for(int i=0;i<n;i++){
	        
	        for(int prev = 0 ; prev<i;prev++){
	            
	            if(nums[prev] < nums[i] && dp[prev]+1 > dp[i]){
	                
	                dp[i] = dp[prev] + 1;
	            }
	        }
	        
	    }
	    
	    for(int i=n-1;i>=0;i--){
	        
	        for(int prev = n-1;prev>i;prev--){
	            
	            if( nums[prev] < nums[i] && dp1[prev] + 1 > dp1[i]){
	                
	                dp1[i] = dp1[prev] + 1;
	            }
	        }
	        
	    }
	    
	    int mx = 1;
	    
	    for(int i=0;i<n;i++){
	        
	        mx = max( mx , dp[i]+dp1[i]);
	    }
	    
	    return mx-1;
	    
	}
};
