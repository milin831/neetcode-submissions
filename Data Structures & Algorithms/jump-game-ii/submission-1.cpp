class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(),maxval=0,countjmp=0,curr=0;
        for(int i=0;i<n-1;i++){
            maxval=max(maxval,i+nums[i]);
            if(i==curr){
                countjmp++;
                curr=maxval;
            }
        }
        return countjmp;
    }
};
