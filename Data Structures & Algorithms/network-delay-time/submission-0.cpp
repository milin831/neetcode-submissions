class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int src=times[i][0];
            int des=times[i][1];
            int weight=times[i][2];
            adj[src].push_back({des,weight});
        }
        int maxres=0;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
            > q;
        q.push({0,k});
        vector<int> dist(n+1,INT_MAX),vis(n+1,0);
        dist[k]=0;
        while(!q.empty()){
            int weight=q.top().first,node=q.top().second;
            q.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(auto x:adj[node]){
                int des=x.first,weight=x.second;
                if(dist[des]>dist[node]+weight){
                    dist[des]=dist[node]+weight;
                    q.push({dist[des],des});
                }
            } 
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            maxres=max(maxres,dist[i]);
        }
        return maxres;
    }
};
