gfg link : https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=boolean-parenthesization

int t[202][202][2];
int mod = 1003;

class Solution{
    
    private:
    
    int ways(string&S, int i, int j, bool istrue){
        
        if(i>j)return 0;
        
        if(t[i][j][istrue]!=-1)return t[i][j][istrue];
        
        if(i==j){
            
            if(istrue==true){
                
               return S[i]=='T';
            }
            else{
                
                return S[i]=='F';
            }
        }
        
        int ans  = 0;
        
        for(int k = i+1; k<= j-1 ; k = k+2){
            
            int lt,lf,rt,rf;
            
            if( t[i][k-1][1]!=-1){
                
                lt = t[i][k-1][1];
                
            }
            else{
                
                lt = ways(S,i,k-1,1);
                t[i][k-1][1] = lt;
            }
            
            
            if( t[i][k-1][0]!=-1){
                
                lf = t[i][k-1][0];
            }
            else{
                
                lf = ways(S,i,k-1,0);
                t[i][k-1][0] = lf;
            }
            
            if(t[k+1][j][1]!=-1){
                
                rt = t[k+1][j][1];
            }
            else{
                
                rt = ways(S,k+1,j,1);
                t[k+1][j][1] = rt;
            }
            
            if( t[k+1][j][0]!=-1){
                
                rf = t[k+1][j][0];
            }
            else{
                
                rf = ways(S,k+1,j,0);
                t[k+1][j][0] = rf;
            }
            
            
            if(S[k]=='&'){
                
                if(istrue){
                    
                    ans+= (lt*rt)%mod;
                }
                else{
                    
                    ans+= (lt*rf + lf*rt + lf*rf )%mod;
                }
            }
            else if( S[k]=='|'){
                
                if(istrue){
                    
                    ans+= (lt*rf + lf*rt + lt*rt)%mod;
                }
                else{
                    
                    ans+= (lf*rf)%mod;
                }
            }
            else if( S[k] == '^'){
                
                if(istrue){
                    
                    ans+= (lt*rf + lf*rt)%mod;
                }
                else{
                    
                    ans+= (lf*rf + lt*rt)%mod;
                }
            }
            
        }
        
        return t[i][j][istrue] =  ans%mod;
    }
    
public:
    int countWays(int N, string S){
        // code here
        
        memset(t,-1,sizeof(t));
        
        return ways(S,0,N-1,true);
    }
};
