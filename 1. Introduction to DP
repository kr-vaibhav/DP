gfg link : https://practice.geeksforgeeks.org/problems/introduction-to-dp/1

int t[1002];
int mod = 1e9+7;

class Solution {
  public:
  
    Solution(){
        memset(t,-1,sizeof(t));
    }
    
    long long int topDown(int n) {
        // code here
        
        if(n==0)return 0;
        if(n==1)return 1;
        
        if(t[n]!=-1) return t[n]%mod;
        
        int l,r;
        
        if(t[n-1]!=-1) l = t[n-1]%mod;
        else{
            t[n-1] = topDown(n-1);
            l = t[n-1]%mod;
        }
        
        if( t[n-2]!=-1) r = t[n-2]%mod;
        else{
            
            t[n-2] = topDown(n-2);
            r = t[n-2]%mod;
        }
        
        return t[n] = (l+r)%mod;
        
    }
    long long int bottomUp(int n) {
        // code here
        
        int t[n+1];
        t[0]=0;
        t[1]=1;
        
        for(int i=2;i<n+1;i++){
            
            t[i] = (t[i-1]+t[i-2])%mod;
        }
        
        return t[n]%mod;
        
    }
};
