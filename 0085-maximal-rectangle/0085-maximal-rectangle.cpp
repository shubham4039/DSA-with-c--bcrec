class Solution {
public:
    int maxArea(vector<int>& heights){
        int n = heights.size();
        vector<int> prev(n), next(n);
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxi = 0;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, heights[i] * (next[i]-prev[i]-1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(); //row size
        int n = matrix[0].size(); //column size

        vector<int> height(n);

        for(int i=0; i<n; i++){
            height[i] = (matrix[0][i] == '1') ? 1 : 0 ;
        }

        int maximumArea = maxArea(height);

        for(int row=1; row<m; row++){
            for(int col=0; col<n; col++){
                if(matrix[row][col] == '0'){
                    height[col] = 0;
                }
                else{
                    height[col] += 1;
                }
            }
            maximumArea = max(maximumArea, maxArea(height));
        }
        return maximumArea;
    }
}; 