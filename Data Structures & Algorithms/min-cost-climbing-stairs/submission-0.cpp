class Solution {
public:
    int helper(vector<int> &cost,int i,vector<int> &dp){
        int n=cost.size();
        if(i>=n) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        dp[i]= cost[i]+min(helper(cost,i+1,dp),helper(cost,i+2,dp));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,INT_MIN);
        return min(helper(cost,0,dp),helper(cost,1,dp));
    }
};
