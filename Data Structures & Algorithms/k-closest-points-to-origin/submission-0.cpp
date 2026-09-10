class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            int distance=sqrt((points[i][0]-0)^2+(points[i][1]-0)^2);
            pq.push({distance,{points[i][0],points[i][1]}});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            auto node=pq.top();
            int d=node.first;
            int s=node.second.first;
            int e=node.second.second;
            pq.pop();
            res.push_back({s,e});
        }
        return res;
    }
};
