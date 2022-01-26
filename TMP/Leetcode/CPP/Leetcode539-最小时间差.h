class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> trans;
        for(auto s : timePoints) {
            int h = stoi(s.substr(0,2)),m = stoi(s.substr(3));
            int t = h * 60 + m;
            trans.push_back(t);
        }
        sort(trans.begin(),trans.end());
        int n = trans.size();
        int ans = INT_MAX;
        for(int i = 0;i < n - 1;i++) {
            ans = min(ans,trans[i + 1] - trans[i]);
        }
        ans = min(ans,trans[0] + 1440 - trans.back());
        return ans;
    }
}; 