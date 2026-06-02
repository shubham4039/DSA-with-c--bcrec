class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashArr(256, -1);
        int left = 0, right = 0, maxLen = 0;  
        int n = s.length();

        while(right < n){
            if(hashArr[s[right]] != -1){
                if(hashArr[s[right]] >= left){
                    left = hashArr[s[right]] + 1;
                }
            }
            maxLen = max(maxLen, right-left+1);
            hashArr[s[right]] = right;
            right++;
        }
        return maxLen;
    }
};