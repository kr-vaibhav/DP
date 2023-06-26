https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution
{  
    private:
    
    int ceil(vector<int>&temp, int val ){

        int n = temp.size();
    
        int i=0,j=n-1;
    
        int ans;
    
        while(i<=j){
    
            int mid = i+(j-i)/2;
    
            if(temp[mid]==val){
                
                i = mid+1;
                
            }
            else if( temp[mid] > val){
    
                ans = mid;
                j = mid-1;
            }
            else{
    
                i=mid+1;
            }
        }
    
        return ans;
}

    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       
        vector<int>temp;
        temp.push_back(arr[0]);

        for(int i=1;i<n;i++){

            if(arr[i] > temp.back()){

            temp.push_back(arr[i]);
            }
            
            else{

            int index = ceil(temp,arr[i]);

            temp[index] = arr[i];
            }
        }

        return temp.size();
    }
};
