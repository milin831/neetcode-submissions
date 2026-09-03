class Solution {
public:
    void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis){
        if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]=='1' && !vis[row][col]){
            vis[row][col]=1;
            dfs(row+1,col,grid,vis);
            dfs(row,col+1,grid,vis);
            dfs(row-1,col,grid,vis);
            dfs(row,col-1,grid,vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),island=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1' && !vis[i][j]){
                    island++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return island;
    }
};
