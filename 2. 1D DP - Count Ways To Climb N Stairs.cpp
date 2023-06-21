gfg link : https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

int mod = 1e9+7;
int t[10002];
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    Solution(){
        memset(t,-1,sizeof(t));
    }
    
    
    int countWays(int n)
    {
        // your code here
        if(n<0)return 0;
        if(n==0)return 1;
        
        if(t[n]!=-1) return t[n];
        
        int l,r;
        
        if(t[n-1]!=-1)l=t[n-1]%mod;
        else{
            l = countWays(n-1)%mod;
            t[n-1] = l;
        }
        
        if(t[n-2]!=-1)r=t[n-2]%mod;
        else{
            r = countWays(n-2)%mod;
            t[n-2] = r;
        }
        
        
        return t[n] = ( l + r )%mod;
    }
};
