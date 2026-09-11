class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string s=strs[i];
            string t=s;
            sort(t.begin(),t.end());
            m[t].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& x : m){
            result.push_back(x.second);
        }
        return result;
    }
};
