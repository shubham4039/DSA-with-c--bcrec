class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, jumps = 0;
        int n = nums.size();

        while(r < n-1){
            int lastInd = 0;
            for(int i = l; i <= r; i++){
                lastInd = max(i + nums[i], lastInd);
            }
            l = r+1;
            r = lastInd;
            jumps = jumps + 1;
        }
        return jumps;
    }
};