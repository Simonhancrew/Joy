class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(int i = 0;i < list1.size();i++) mp[list1[i]] = i;
        int sum = INT_MAX;
        for(int i = 0;i < list2.size();i++){
            string& s = list2[i];
            if(mp.count(s)){
                int k = i + mp[s];
                if(k < sum) {
                    sum = k;
                    ans = {s};
                } else if(k == sum) {
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};