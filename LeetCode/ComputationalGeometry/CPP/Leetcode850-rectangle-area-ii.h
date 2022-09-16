#define x first
#define y second 

// 横坐标排序，找出独立不重合的横坐标区间
// 在这个区间的基础上，找到往上的纵坐标和横坐标区间重合的部分。
// 做一下乘法。值得注意的是，纵坐标区间可能存在不连续的，需要不断更新

class Solution {
public:
    using LL = long long;
    using PII = pair<int,int>;

    const int P = 1e9 + 7;
    LL calcu(vector<vector<int>>& rec,int a,int b) {
        vector<PII> coy;
        for(auto r : rec) {
            if(r[0] <= a && r[2] >= b) {
                coy.emplace_back(r[1],r[3]);
            }
        }
        sort(coy.begin(),coy.end());
        LL res = 0,st = -1,ed = -1;
        for(auto c : coy) {
            if(c.x > ed) {
                res += ed - st;
                st = c.x,ed = c.y;
            }else if(c.y > ed) {
                ed = c.y;
            }
        }
        res += ed - st;
        return res * (b - a);
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> cox;
        for(auto &r : rectangles) {
            cox.push_back(r[0]);
            cox.push_back(r[2]);
        }
        sort(cox.begin(),cox.end());
        LL res = 0;
        for(int i = 1;i < cox.size();i++) {
            res += calcu(rectangles,cox[i - 1],cox[i]);
        }
        return res % P;
    }
};
