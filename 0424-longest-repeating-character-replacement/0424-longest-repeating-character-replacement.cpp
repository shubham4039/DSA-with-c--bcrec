class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxLen=0, maxFreq=0;
        int n=s.length();
        int hashArr[26]={0};

        while(r<n){
            hashArr[s[r] - 'A']++;
            maxFreq = max(maxFreq, hashArr[s[r] - 'A']);
            int changes = (r-l+1)-maxFreq;

            if(changes > k){
                hashArr[s[l] - 'A']--;
                maxFreq=0;
                l++;

                for(int i = 0; i<26; i++){
                    maxFreq = max(maxFreq, hashArr[i]);
                }
                changes = (r-l+1)-maxFreq;
            }
           
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};