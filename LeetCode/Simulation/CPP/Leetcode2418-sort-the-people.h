class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> rec;
        int n = names.size();
        for (int i = 0;i < n;i++) {
            rec.emplace_back(names[i], heights[i]);
        }
        sort(rec.begin(), rec.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.second > rhs.second;
        });
        for (int i = 0; i < n;i++) {
            names[i] = rec[i].first;   
        }
        return names;
    }
};