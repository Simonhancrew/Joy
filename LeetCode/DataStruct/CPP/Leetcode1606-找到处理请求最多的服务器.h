#include <queue>
#include <set>

using namespace std;

/*
    模拟 + 有序集合 + 优先队列
    把可以承接处理的处理器加入free有序集合中，然后用一个小顶堆维护
    过期时间。
    遍历到达的时间，检测小顶堆中的过期事件，释放服务器
    然后二分出合适的结果，不存在则环形的往下找
    然后将最终的过期时间 + 服务器id加入到小顶堆中。将当前使用的服务器移除
*/

class Solution {
public:
    typedef pair<int,int> PII;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        for(int i = 0;i < k;i++) free.insert(i);
        priority_queue<PII,vector<PII>,greater<PII>> heap;
        vector<int> rec(k);
        for(int i = 0;i < arrival.size();i++){
            while(!heap.empty() && heap.top().first <= arrival[i]) {
                auto t = heap.top();
                heap.pop();
                free.insert(t.second);
            }
            if(free.empty()) continue;
            auto p = free.lower_bound(i % k);
            if(p == free.end()) p = free.begin();
            heap.push({arrival[i] + load[i],*p});
            rec[*p]++;
            free.erase(p);
        }
        int mx = *max_element(rec.begin(),rec.end());
        vector<int> ans;
        for(int i = 0;i < k;i++) {
            if(rec[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};