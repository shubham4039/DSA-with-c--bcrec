class Solution {
public:
    long long findMinMax(vector<int>& nums, bool findingMax){
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && (findingMax ? nums[st.top()] < nums[i]: nums[st.top()] > nums[i])){
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && (findingMax ? nums[st.top()] <= nums[i] : nums[st.top()] >= nums[i])){
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum =0;
        for(int i=0; i<n; i++){
            long long count = (long long)(i - prev[i])*(next[i] - i);
            sum += count*nums[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return findMinMax(nums, true) - findMinMax(nums, false);
    }
};