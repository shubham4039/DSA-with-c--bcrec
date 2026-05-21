class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<pair<int, int>> st;

        for(int i =0; i<n; i++){
            while(!st.empty() && st.top().first < temperatures[i]){
                int lastIndex = st.top().second;
                ans[lastIndex] = i - lastIndex;

                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};