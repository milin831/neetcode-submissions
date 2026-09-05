class Solution {
public:
    int distance(vector<vector<int>>& points,int x,int y){
        return abs(points[x][0]-points[y][0])+abs(points[x][1]-points[y][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        vector<int> vis(n);
        pq.push({0,0});
        int total=0;
        while(!pq.empty()){
            auto nodeinfo=pq.top();
            int weight=nodeinfo.first,node=nodeinfo.second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            total+=weight;
            for(int i=0;i<n;i++){
                int edge=distance(points,node,i);
                pq.push({edge,i});
            }
        }
        return total;
    }
};
