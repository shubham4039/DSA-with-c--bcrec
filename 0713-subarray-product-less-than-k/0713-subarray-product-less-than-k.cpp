class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int l = 0;
        int prod = 1;
        int cnt = 0;
        int n = nums.size();
        for(int r=0; r<n; r++){
            prod *= nums[r];
            while(prod >= k){
                prod /= nums[l];
                l++;
            }
            cnt += (r-l+1);
        }
        return cnt;
    }
};