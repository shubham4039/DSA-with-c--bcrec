class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()) return false;
        unordered_map<char, int> counts;
        for(char c:s){
            counts[c]++;
        }
        for(char c:t){
            counts[c]--;
            if(counts[c]<0){
                return false;
            }
        }
        return true;
    }
};