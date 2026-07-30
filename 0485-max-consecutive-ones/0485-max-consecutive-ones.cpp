class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left=0, maxi=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                maxi= max(maxi, i-left+1);
            }
            else{
                left = i+1;
            }
        }
        return maxi;
    }
};