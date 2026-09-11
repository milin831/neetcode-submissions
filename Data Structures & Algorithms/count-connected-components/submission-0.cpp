class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int len=edges.size();
        vector<int> adj[n];
        for(int i=0;i<len;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        vector<int> vis(n,0);
        int com=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                if(vis[node])continue;
                vis[node]=1; 
                for(int x:adj[node]){
                    q.push(x);
                }
            }
            com++;
        }
        return com;
    }
};
