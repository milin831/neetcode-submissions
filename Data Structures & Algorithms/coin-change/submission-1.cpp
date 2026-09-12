class Solution {
public:
    int helper(vector<int>& coins,int index, int amount,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(index>=coins.size() || amount<0) return 1e9;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int skip=helper(coins,index+1,amount,dp);
        int take=1+helper(coins,index,amount-coins[index],dp);
        dp[index][amount]=min(skip,take);
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=helper(coins,0,amount,dp);
        return ans==1e9?-1:ans;
    }
};
