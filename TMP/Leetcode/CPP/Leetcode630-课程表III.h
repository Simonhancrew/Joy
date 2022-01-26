#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
    不难知道应该按照ddl排序，(t1,d1),(t2,d2)均能完成的话。
        cost1 = {
            t1  <= d1
            t1 + t1 <= d2
        }
        cost2 = {
            t2 <= d2
            t2 + t1 <= d1
        }
    如果d1 <= d2,可以从t2 + t1 <= d1推到 t1 + t2 <= d2
    但是反之，不行。
    实际过程中，不妨设f[i - 1]表示当前最优解：{
        选择课程最多：tot
        用时最短：x
    }
    因此，到选择课程i时，如果x + cs[0] < cs[1],无脑加入
    如果x + cs[0] > cs[1],不可能选到比f[i-1]情况下更多的课，但是可以考虑优化最短时间
    考虑到此时的cs[1]一定是大于等于目前学习时间总限制上线的
    在[0,i]中去掉一个学习时间最长的课，一定可以做到耗时更短，且满足时间限制。
*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& lhs,vector<int>& rhs) {
            return lhs[1] < rhs[1];
        });
        priority_queue<int> q;
        int tot = 0;
        for(auto &cs : courses) {
            tot += cs[0];
            q.push(cs[0]);
            if(tot > cs[1]) {
                int t = q.top();
                q.pop();
                tot -= t;
            }
        }
        return q.size();
    }
};