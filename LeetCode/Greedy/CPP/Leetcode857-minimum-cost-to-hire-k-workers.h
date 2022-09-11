#include <vector>
#include <queue>

using namespace std;

// 不难发现要求quality的和最后支付的wage的比值都要相等
// 等价于比值x * qa >= wa --> x >= wa / qa
// 所以将所有的比值放入vec,排序
// 针对当前比值，选取k个qality最小的，最后乘起来的sum就是结果，从头到尾取最小的

class Solution {
public:
    using PDI = pair<double,int>;
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<PDI> rec;
        int n = quality.size();
        for(int i = 0;i < n;i++) {
            rec.emplace_back(1.0 * wage[i] / quality[i],i);
        }
        sort(rec.begin(),rec.end());
        double ans = 1e18;
        int sum = 0;
        priority_queue<int> heap;
        for(int i = 0;i < n;i++) {
            heap.push(quality[rec[i].second]);
            sum += quality[rec[i].second];
            if(heap.size() > k) {
                sum -= heap.top();
                heap.pop();
            }
            if(heap.size() == k) {
                ans = min(ans,sum * rec[i].first);
            }
        }
        return ans;
    }
};