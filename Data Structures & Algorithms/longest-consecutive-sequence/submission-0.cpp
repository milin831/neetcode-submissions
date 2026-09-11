class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxval=0;
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(m.find(nums[i]-1) != m.end()) m[nums[i]]=m[nums[i]-1]+1;
            else m[nums[i]]=1;
            if(maxval<m[nums[i]]) maxval=m[nums[i]];
        }
        return maxval;
    }
};
