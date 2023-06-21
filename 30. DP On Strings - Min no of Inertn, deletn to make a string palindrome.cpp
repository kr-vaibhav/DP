gfg link : https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m   =   str1.length();
	    int n   =   str2.length();
	    
	    int t[m+1][n+1];
	    for(int i=0;i<m+1;i++)t[i][0]=0;
	    for(int i=0;i<n+1;i++)t[0][i]=0;
	    
	    for(int i=1;i<m+1;i++){
	        
	        for(int j=1;j<n+1;j++){
	            
	            
	            if(str1[i-1] == str2[j-1]){
	                
	                t[i][j] =   1  +  t[i-1][j-1];
	            }
	            else{
	                
	                t[i][j] =   max( t[i-1][j], t[i][j-1]);
	            }
	        }
	    }
	    
	    int not_common_in_str1  =   m - t[m][n];
	    
	    int not_common_from_str1  =   n - t[m][n];
	    
	    return not_common_in_str1 + not_common_from_str1;
	    
	    
	    
	} 
};
