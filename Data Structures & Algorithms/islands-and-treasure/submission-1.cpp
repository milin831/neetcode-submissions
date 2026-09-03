class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }            
            }
        }

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();
            vis[r][c]=1;
            int dr[]={1,-1,0,0};
            int dc[]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int row=r+dr[k];
                int col=c+dc[k];
                if(row<0 || row>=n || col<0 || col>=m || grid[row][col]==-1 || grid[row][col]==0 || vis[row][col]) continue;
                if(grid[row][col]==2147483647){
                    grid[row][col]=time+1;
                    vis[row][col]=1;
                    q.push({{row,col},time+1});
                }
            }
        }
    } 
};
