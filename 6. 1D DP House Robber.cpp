gfg link : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

int t[10002];

class Solution
{   private:

    int solve(int arr[], int i, int n){
        
        if(i>=n)return 0;
        
        if(t[i]!=-1) return t[i];
        
        int loot        = arr[i] + solve(arr,i+2,n);
        int not_loot    =  solve(arr,i+1,n);
        
        return t[i] = max(loot,not_loot);
    }
    
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        memset(t,-1,sizeof(t));
        
        return solve(arr,0,n);
    }
};
