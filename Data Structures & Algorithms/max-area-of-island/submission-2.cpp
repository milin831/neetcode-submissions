class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        map<int,vector<pair<int,int>>> freq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int num=1,result=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==0 || vis[row][col]) continue;
                vector<pair<int,int>> ans;
                q.push({row,col});
                while(!q.empty()){
                    int r=q.front().first,c=q.front().second;
                    q.pop();
                    vis[r][c]=1;
                    ans.push_back({r,c});
                    int dr[]={1,-1,0,0};
                    int dc[]={0,0,1,-1};
                    for(int k=0;k<4;k++){
                        int newrow=r+dr[k];
                        int newcol=c+dc[k];
                        if(newrow<0 || newrow>=n || newcol<0 || newcol>=m || grid[newrow][newcol]==0 || vis[newrow][newcol]) continue;
                        vis[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
                }
                freq[num]=ans;
                if(ans.size()>result) result=ans.size();
            }
        }
        return result;
    }
};
