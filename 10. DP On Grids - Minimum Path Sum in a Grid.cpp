gfg link : https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1

typedef pair<int,pair<int,int>>ppi;

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        priority_queue<ppi, vector<ppi>, greater<ppi>>minh;
        
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        
        distance[0][0] = grid[0][0];
        
        int delrow[4] = {0,0,-1,+1};  // left, right, up ,down 
        int delcol[4] = {-1,+1,0,0};
        
       
        minh.push({distance[0][0],{0,0}});  //{ distance , { row ,col } }
        
        while(!minh.empty()){
            
            int dist = minh.top().first;
            int r    = minh.top().second.first;
            int c    = minh.top().second.second;
            minh.pop();
            
            for(int k=0; k<4;k++){
                
                int nrow = delrow[k] + r;
                int ncol = delcol[k] + c;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    
                    if(distance[nrow][ncol] > dist + grid[nrow][ncol]){
                        
                        distance[nrow][ncol] = dist + grid[nrow][ncol];
                        
                        minh.push({ distance[nrow][ncol], {nrow,ncol}});
                        
                        if(nrow==n-1 && ncol==m-1)break;
                    }
                }
            }
        }
        
        return distance[n-1][m-1];
        
        
    }
};
