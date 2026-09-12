class Solution {
public:
    int helper(vector<int>& coins,int index, int amount){
        if(amount==0) return 0;
        if(index>=coins.size() || amount<0) return 1e9;
        int skip=helper(coins,index+1,amount);
        int take=1+helper(coins,index,amount-coins[index]);
        return min(skip,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=helper(coins,0,amount);
        return ans==1e9?-1:ans;
    }
};
