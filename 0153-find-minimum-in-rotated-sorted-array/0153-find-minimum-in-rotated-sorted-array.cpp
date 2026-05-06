class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int ans = INT_MAX;
        while(low <= high){
            if(nums[low]<=nums[high]){
                ans = min(ans, nums[low]);
                low++;
            }
            else{
                ans = min(ans, nums[high]);
                high--;
            }
        }
        return ans;    
    }
};