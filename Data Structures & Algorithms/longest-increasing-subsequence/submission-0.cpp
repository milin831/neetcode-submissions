class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        for(int x:nums){
            int pos=0;
            while(pos<temp.size() && temp[pos]<x) pos++;
            if(pos==temp.size()) temp.push_back(x);
            else temp[pos]=x;
        }
        return temp.size();
    }
};
