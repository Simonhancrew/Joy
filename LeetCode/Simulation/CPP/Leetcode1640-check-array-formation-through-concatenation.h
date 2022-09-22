class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> mp;
        int n = pieces.size();
        for(int i = 0;i < n;i++) {
            mp[pieces[i][0]] = i;
        }
        n = arr.size();
        for(int i = 0;i < n;) {
            if(!mp.count(arr[i])) return false;
            auto& tmp = pieces[mp[arr[i]]];
            int cnt = tmp.size();
            for(int j = 0;j < cnt;j++) {
                if(tmp[j] != arr[i]) return false;
                i++;
            }
        }
        return true;
    }
};
