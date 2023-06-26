https://practice.geeksforgeeks.org/problems/longest-string-chain/1

bool comp(string &s1, string& s2){

        return s1.size() < s2.size();
        }

class Solution {
  
  private: 

    
    bool check(string &s1, string &s2){

        int n = s1.length();
        int m = s2.length();

        if(n!=m+1)return false;

        int i=0,j=0;

        while(i<n){

            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else i++;
        }

        if(i==n && j==m)return true;
        return false;
    }
public:

    
  
    int longestChain(int n, vector<string>& words) {
        // Code here
        if(words.size()==1)return 1;

        sort(words.begin(),words.end(),comp);

        vector<int>dp(n+1,1);

        int mx = 1;

        for(int i=0;i<n;i++){

            for(int prev= 0;prev<i;prev++){

                if( check(words[i],words[prev]) && dp[prev]+1 > dp[i] ){

                    dp[i] = 1 + dp[prev];

                }
            }

            if(dp[i] > mx ){

                mx = dp[i];
            }

        }



        return mx;
    }
};
