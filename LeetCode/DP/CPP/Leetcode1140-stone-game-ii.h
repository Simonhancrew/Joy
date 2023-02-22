// 当选完之后，假设选了x
// 下一个能选的[x + 1, n], 可选的上限就是max(x, m)
// 构成一个子问题， 可以递推的算。状态需要倒序的推
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> s(n + 1);
        vector<vector<int>> f(n + 2, vector<int> (n + 1));
        for (int i = 1;i <= n;i++) {
            s[i] = s[i - 1] + piles[i - 1];
        }
        for (int i = n;i;i--) {
            for (int j = 1;j <= n;j++) {
                for (int k = 1;i + k - 1 <= n && k <= 2 * j;k++) {
                    f[i][j] = max(f[i][j], s[n] - s[i - 1] - f[i + k][max(k, j)]);
                }
            }
        }
        return f[1][1];
    }
};
