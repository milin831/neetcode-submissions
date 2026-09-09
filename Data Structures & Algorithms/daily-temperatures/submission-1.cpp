class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        int n=t.size();
        vector<int> res(n,0);
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && t[s.top()]<t[i]){
                int index=s.top();
                s.pop();
                res[index]=i-index;
            }
            s.push(i);
        }
        return res;
    }
};
