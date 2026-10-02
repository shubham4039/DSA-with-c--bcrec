class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int cnt = 1;
        int end = intervals[0][1];

        int n = intervals.size();

        for(int i=0; i < n; i++){
            if(intervals[i][0] >= end){
                cnt++;
                end = intervals[i][1];
            }
        }
        
        return n-cnt;
    }
};