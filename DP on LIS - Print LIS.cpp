https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        
        vector<int> dp(n,1);
        vector<int> back(n);
        
        int last=0;
        int maxi=1;
        
        
        for(int i=0;i<n;i++){
            
            back[i]=i;
            
            for(int j=0;j<i;j++){
                
                if(arr[j]<arr[i] && dp[j]+1>dp[i]){
                    
                    dp[i]=1+dp[j];
                    back[i]=j;
                }
            }
            
            if(dp[i]>maxi){
                
                maxi=dp[i];
                last=i;
            }
        }
        
        vector<int> ans;
        
        ans.push_back(arr[last]);
        
        while(back[last]!=last){
            
            last=back[last];
            ans.push_back(arr[last]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
