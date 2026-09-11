class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            if (m.find(nums[i]) != m.end())m[nums[i]]++;
            else m[nums[i]]=1;
        }
        vector<pair<int,int>> vec(m.begin(),m.end());
        sort(vec.begin(),vec.end(),[](const auto &a,const auto &b){
            return a.second>b.second;
        });
        vector<int> res;
        for(const auto &pair:vec){
            if(k==0) break;
            k--;
            res.push_back(pair.first);
        }
        return res;
    }
};
