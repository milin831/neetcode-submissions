class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),maxval=nums[0],countjmp=1;
        for(int i=1;i<n;i++){
            if(maxval==n-1) break;
            if(maxval<i+nums[i]){
                maxval=i+nums[i];
                countjmp++;
            }
        }
        return countjmp;
    }
};
