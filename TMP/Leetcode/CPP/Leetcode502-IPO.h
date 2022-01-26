#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

// 首先看数据范围，一般1000以内的话考虑dp，1w的话考虑贪心
// 其次，这里我们考虑从小到大排序cost（这里是纯利润，一定增长），所以可以考虑动态维护一个堆，把能选择的利润全部拿进来，每次选最大，做完之后丢弃
// 大顶堆天然适合做这个事

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> q;
        for(int i = 0;i < n;i++) q.push_back({capital[i],profits[i]});
        sort(q.begin(),q.end());
        priority_queue<int> heap;
        int i = 0;
        while(k--){
            while(i < n && w >= q[i].first) heap.push(q[i].second),i++;
            if(heap.empty()) break;
            auto t = heap.top();
            w += t;
            heap.pop();
        }
        return w;
    }
};