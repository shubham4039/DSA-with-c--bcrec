class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1;
        int maxWater = 0;

        while(start < end){
            int width = (end - start);
            int heig = min(height[start], height[end]);
            maxWater = max(maxWater, width*heig);

            if(height[start] < height[end]) start++;
            else end--;
        }
        return maxWater;
    }
};