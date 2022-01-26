#include <map>
#include <vector>

using namespace std;


class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rec) {
        map<pair<int,int>,int> mp;// unordered_map用pair需要加入hash比较
        long long res = 0;
        for(auto& x : rec){
            int t = gcd(x[0],x[1]);
            x[0] /= t;
            x[1] /= t;
            res += mp[{x[0],x[1]}];
            mp[{x[0],x[1]}]++;
        }
        return res;
    }
    int gcd(int a,int b){
        return b ? gcd(b,a % b): a;
    }
};

#if 0
//用double + hash做，最后高斯公式
#endif