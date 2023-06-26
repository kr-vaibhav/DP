gfg link : https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=palindromic-patitioning


int dp[501][501];

class Solution{
public:

    
    
    bool isPalindrome(string s, int i, int j){
        
        while(i<j){
            
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
    }

int solve(string s, int i, int j){
   
    if(i>=j)
    return 0;
    
    if(isPalindrome(s, i, j))
    return 0;
    
    if(dp[i][j] != -1)
    return dp[i][j];
    
    int mn = INT_MAX;
    for(int k = i ;k<j ;k++)
    {
        int l, r;
        
        if(dp[i][k] != -1)
        l = dp[i][k];
        else{
            l = solve(s, i, k);
            dp[i][k] = l;
        }
        
        if(dp[k+1][j] != -1 )
        r = dp[k+1][j];
        else{
            r = r = solve(s, k+1, j);
            dp[k+1][j] = r;
        }
        
        int ans =  1 + l + r;
        mn = min(mn, ans);
    }
    return dp[i][j] = mn;
}


    
    int palindromicPartition(string str)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int i=0 , j=str.length()-1;
        return solve(str, i, j);
    }
};
