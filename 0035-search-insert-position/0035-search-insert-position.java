class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i =0;i<nums.length;++i){
            int CurrentValue = nums[i];
            if(CurrentValue >= target){
                return i;

            }
        }
        return nums.length;
    }
}