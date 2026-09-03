class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& heights,vector<vector<int>>& vis){
            vis[row][col]=1;
            int dr[]={1,-1,0,0};
            int dc[]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int r=row+dr[k];
                int c=col+dc[k];
                if(r<0 || r>=heights.size() || c<0 || c>=heights[0].size() || vis[r][c]) continue;
                if(heights[row][col]>heights[r][c]) continue;
                dfs(r,c,heights,vis);
            }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int> (m,0)),atlantic(n,vector<int> (m,0));
        for(int i=0;i<n;i++) dfs(i,0,heights,pacific);
        for(int i=0;i<m;i++) dfs(0,i,heights,pacific);
        for(int i=0;i<n;i++) dfs(i,m-1,heights,atlantic);
        for(int i=0;i<m;i++) dfs(n-1,i,heights,atlantic);
        
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1) res.push_back({i,j});
            }
        }
        return res;
    }
};
