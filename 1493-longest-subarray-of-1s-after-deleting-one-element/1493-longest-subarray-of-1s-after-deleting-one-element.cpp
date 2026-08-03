class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, n = nums.size();
        int ans = 0, zeroCnt = 0;
        for(int r = 0; r<n; r++){
            if(nums[r] == 0) zeroCnt++;
            while(zeroCnt > 1){
                if(nums[l] == 0){
                    zeroCnt--;
                }
                l++;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};