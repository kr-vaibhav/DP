leetcode link : https://leetcode.com/problems/triangle/

int t[1002][1002];

class Solution {
    private:

    int solve(int i, int j, int n, vector<vector<int>>& triangle ){

        if( i>= n || j>=triangle[i].size()) return 0;

        if(t[i][j]!=-1) return t[i][j];
        
        int down = solve(i+1,j,n,triangle) + triangle[i][j];

        int down_right = solve(i+1, j+1, n, triangle) + triangle[i][j];

        if(i==n-1) return min(down,down_right);

        return t[i][j] = min(down,down_right);

    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        memset(t,-1,sizeof(t));

        return solve(0,0,n,triangle);
    }
};
