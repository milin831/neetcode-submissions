class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int result=0,left=0,right=n-1;
        while(left<right){
            result=max(result,min(heights[left],heights[right])*(right-left));
            if(heights[left]>heights[right]) right--;
            else left++;
        }
        return result;
    }
};
