class Solution {
public:
    // 贪心， 最优解要么往左走之后往右， 要么往右走之后往左
    // 从大到小枚举左端点， 右端点是不增的
    // 从小到大枚举右端点， 左端点是不减的
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int m = lower_bound(fruits.begin(), fruits.end(), startPos, [](const vector<int> fruit, int value) {
            return fruit[0] < value;
        }) - fruits.begin();
        int lcnt = 0, rcnt = 0;
        int ans = 0;
        for (int i = m;i < n;i++) rcnt += fruits[i][1];
        for (int i = m - 1, j = n - 1;i >= 0;i--) {
            int lp = startPos - fruits[i][0];
            if (lp > k) break;
            lcnt += fruits[i][1];
            while (j >= m && lp + fruits[j][0] - fruits[i][0] > k) {
                rcnt -= fruits[j][1];
                j--;
            }
            ans = max(ans, rcnt + lcnt);
        }
        lcnt = rcnt = 0;
        for (int i = 0;i < m;i++) {
            lcnt += fruits[i][1];
        }
        for (int i = 0, j = m;j < n;j++) {
            int rp = fruits[j][0] - startPos;
            if (rp > k) break;
            rcnt += fruits[j][1];
            while (i < m && rp + fruits[j][0] - fruits[i][0] > k) {
                lcnt -= fruits[i][1];
                i++;
            }
            ans = max(ans, lcnt + rcnt);
        }

        return ans;
    }
};