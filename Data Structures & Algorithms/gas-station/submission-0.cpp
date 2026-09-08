class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size(),sum=0;
        int tank=0,index=0;
        for(int i=0;i<n;i++){
            if(tank<0){
                index=i;
                tank=0;
            }
            tank+=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
        }
        if(sum<0) return -1;  
        return tank; 
    }
};
