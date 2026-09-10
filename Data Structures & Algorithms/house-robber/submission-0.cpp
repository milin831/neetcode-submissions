class Solution {
public:
    int helper(vector<int>& nums,int i,bool istrue,vector<vector<int>>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i][istrue]!=INT_MIN) return dp[i][istrue];
        if(istrue==1) dp[i][istrue]=max(nums[i]+helper(nums,i+1,0,dp),helper(nums,i+1,1,dp));
        else dp[i][istrue]=helper(nums,i+1,1,dp);
        return dp[i][istrue];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,INT_MIN));
        return helper(nums,0,1,dp);
    }
};
