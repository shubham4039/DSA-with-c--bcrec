class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int &it: nums){
            mp[it]++;
        }

        priority_queue<p , vector<p>, greater<p>> pq;

        for(auto &it:mp){
            int freq = it.second;
            int val = it.first;

            pq.push({freq, val});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};