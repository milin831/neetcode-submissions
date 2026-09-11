class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        res.push_back(nums[nums.size()-1]);
        k--;
        for(int i=nums.size()-1;i>0;i--){
            if(k==0) continue;
            while(nums[i]==nums[i-1]) i--;
            k--;
            res.push_back(nums[i-1]);
        }
        return res;
    }
};
