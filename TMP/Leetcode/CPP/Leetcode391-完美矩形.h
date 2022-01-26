#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef pair<int,int> PII;
    typedef long long LL;
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<PII,int> mp;
        LL sum = 0;
        for(auto &x : rectangles){
            int a = x[0],b = x[1],c = x[2],d = x[3];
            ++mp[{a,b}],++mp[{a,d}],++mp[{c,b}],++mp[{c,d}];
            sum += LL(c-a) * (d - b);
        }
        vector<vector<int>> ones;
        for(auto &[p,c] : mp){
            if(c == 1) ones.push_back({p.first,p.second});
            else if(c == 3) return false;
        }
        if(ones.size() != 4) return false;
        sort(ones.begin(),ones.end());
        LL sum2 = (LL)(ones[3][1] - ones[0][1]) * (ones[3][0] - ones[0][0]);
        return sum == sum2;
    }
};