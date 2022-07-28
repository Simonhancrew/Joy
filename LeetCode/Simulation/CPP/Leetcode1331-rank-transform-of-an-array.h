class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(),tmp.end());
        unordered_map<int,int> rank;
        int n = arr.size();
        for(int i = 0,cnt = 1;i < n;i++) {
            if(!rank.count(tmp[i])) {
                rank[tmp[i]] = cnt++;
            }
        }
        vector<int> ans(arr.size());
        for(int i = 0;i < n;i++) {
            ans[i] = rank[arr[i]];
        }
        return ans;
    }
};