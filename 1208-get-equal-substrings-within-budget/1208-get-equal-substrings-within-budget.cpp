class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, curCost = 0, maxLen = 0;
        int n = s.size();

        for(int j = 0; j<n; j++){
            curCost += abs(s[j]-t[j]);
            while(curCost > maxCost){
                curCost -= abs(s[i]-t[i]);
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};