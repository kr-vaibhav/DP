gfg link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

int t[1002][1002];


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    Solution(){
        
        memset(t,-1,sizeof(t));
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       if( W==0 || n==0)return 0;
       
       if(t[n][W]!=-1)return t[n][W];
       
       if(wt[n-1]<=W){
           
           return  t[n][W] = max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),  knapSack(W, wt, val, n-1));
           
       }
       
       else return t[n][W] = knapSack(W,wt,val,n-1);
    }
};
