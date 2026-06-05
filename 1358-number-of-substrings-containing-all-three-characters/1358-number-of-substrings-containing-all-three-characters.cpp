class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.length();
        int hashArr[3] = {-1, -1, -1};
        for(int i=0; i<n; i++){
            hashArr[s[i]-'a']=i;
            if(hashArr[0] != -1 && hashArr[1] != -1 && hashArr[2] != -1){
                cnt = cnt + (1 + min({hashArr[0], hashArr[1], hashArr[2]}));
            }
        }
        return cnt;
    }
};