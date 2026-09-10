class KthLargest {
    int num;
    priority_queue<int,vector<int>,greater<int>> pq;

public:

    KthLargest(int k, vector<int>& nums) {
        num=k;
        for(int x:nums){
            pq.push(x);
            if(pq.size()>num) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>num) pq.pop();
        return pq.top();
    }
};