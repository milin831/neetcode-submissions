class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<>
        > q;
        if (n == 1 && m == 1) return grid[0][0];
        vector<vector<int>> vis(n,vector<int>(m,0));
        q.push({grid[0][0],{0,0}});
        while(!q.empty()){
            int weight=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            if(vis[r][c]) continue;
            vis[r][c]=1;
            int dr[]={1,-1,0,0};
            int dc[]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int row=r+dr[k];
                int col=c+dc[k];
                if(row<0 || row>=n || col<0 || col>=m || vis[row][col]) continue;
                int val=max(weight,grid[row][col]);
                if(row==n-1 && col==m-1) return val;
                q.push({val,{row,col}});
            }
        }
        return -1;
    }
};
