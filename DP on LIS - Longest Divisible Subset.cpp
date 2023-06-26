https://practice.geeksforgeeks.org/problems/e866d887f78664cdbf24c61ef9404691f4fb9e59/1

class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& nums) {
        // Code here

        vector<int>t(n,1), parent(n);

        sort(nums.begin(),nums.end());

        int mx = 1, lasti = 0;

        for(int i=0;i<n;i++){

            parent[i] = i;

            for(int prev = 0;prev<i;prev++){

                if(nums[i]%nums[prev]==0 && 1+t[prev] > t[i] ){

                    t[i] = 1 + t[prev];
                    parent[i] = prev;
                }
            }

            if(t[i]>mx){

                mx = t[i];
                lasti = i;
            }
        }

        vector<int>temp;
        temp.push_back(nums[lasti]);

        while(parent[lasti]!= lasti){

            lasti = parent[lasti];
            temp.push_back(nums[lasti]);

        }

        reverse(temp.begin(),temp.end());

        return temp;
    }
};
