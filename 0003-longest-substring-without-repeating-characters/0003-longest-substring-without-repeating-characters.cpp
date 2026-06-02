class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        for(int i=0; i<n; i++){
            int hashArr[256] = {0};
            for(int j = i; j<n; j++){
                if(hashArr[s[j]]>0){
                    break;
                }
                hashArr[s[j]]++;
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};