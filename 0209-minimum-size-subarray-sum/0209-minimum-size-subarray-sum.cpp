class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, sum = 0;
        int ans = INT_MAX;

        int n = nums.size();

        for(int r = 0; r < n; r++){
            sum += nums[r];

            while(sum >= target){
                ans = min(ans, r-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return (ans==INT_MAX) ? 0 : ans;
    }
};