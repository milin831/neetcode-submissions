class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),maxval=nums[0];
        for(int i=1;i<n;i++){
            if(maxval<i) return false;
            maxval=max(maxval,i+nums[i]);
            if(maxval>=n-1) return true;
        }
        return true;
    }
};
