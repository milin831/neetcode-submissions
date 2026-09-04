class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<
            pair<pair<int,int>,int>,
            vector<pair<pair<int,int>,int>>,
            greater<pair<pair<int,int>,int>>
        > pq;
        vector<pair<int,int>> adj[n];
        vector<vector<int>> alldist(n, vector<int>(k + 2, INT_MAX));
        for(int i=0;i<flights.size();i++){
            int start=flights[i][0],end=flights[i][1],dist=flights[i][2];
            adj[start].push_back({end,dist});
        }
        alldist[src][0]=0;
        pq.push({{0,src},0});
        while(!pq.empty()){
            int dist=pq.top().first.first;
            int node=pq.top().first.second;
            int stop=pq.top().second;
            pq.pop();
            if(node==dst) return dist;
            for(auto x:adj[node]){
                if(k>=stop && dist+x.second<alldist[x.first][stop+1]){
                    alldist[x.first][stop+1]=dist+x.second;
                    pq.push({{dist+x.second,x.first},stop+1});
                }
            }
        }
        return -1;
    }
};
