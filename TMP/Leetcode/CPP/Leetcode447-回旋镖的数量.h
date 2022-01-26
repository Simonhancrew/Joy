#include <vector>
#include <unordered_map>

using namespace std;

// 组合数

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size() < 3) return 0;
        int n = points.size();
        int res = 0;
        for(auto& p:points){
            unordered_map<int,int> mp;
            for(auto &q : points){
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                mp[dis]++;
            }
            for(auto& [k,v] : mp){
                res += v * (v - 1);
            }
        }
        return res;
    }
};