class Solution {
private:
    int subarrays(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0, r=0, sum=0, cnt=0, n=nums.size();

        while(r < n){
            sum += (nums[r]%2);
            while(sum > goal){
                sum -= (nums[l]%2);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarrays(nums, k) - subarrays(nums, k-1);
    }
};