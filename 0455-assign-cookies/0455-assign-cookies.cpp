class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();
        int i = 0, j = 0;
        while(j<m && i<n){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }
        return i;
    }
};