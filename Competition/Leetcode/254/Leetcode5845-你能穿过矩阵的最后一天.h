#include <vector>

using namespace std;

// 还可以考虑二分 + BFS，找到上界。上界之后的都不能联通
// check函数就是一个BFS，一个tmp数组，cells中前i天的位置全部标记为0，只有1的位置能走。
// 最后只要走到了row - 1的行，就说明连通。返回true


// 这里使用倒叙遍历 + 并查集维护连通性。两个超级节点代表第一行和最后一行，最后判断两个超级节点的连通性就可以了。
class Solution {
public:
    vector<int> pa;
    int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // 两个超级节点,头尾。
        int top = row * col, down = top + 1;
        pa.resize(top + 2);
        // 倒叙遍历
        for (int i = 0; i < pa.size(); i++) {
            pa[i] = i;
        }
        int n = cells.size();
        int ans = 0;
        vector<vector<bool>> land(row, vector<bool>(col, false));
        for (int i = n - 1; i >= 0; i--) {
            auto t = cells[i];
            int r = t[0] - 1, c = t[1] - 1;
            int idx = r * col + c;
            //cout << "r" << r << "c" << c << endl;
            for (int j = 0; j < 4; j++) {
                int x = r + dx[j], y = c + dy[j];
                //cout << x << ' ' << y << endl;
                if (x >= 0 && x < row && y >= 0 && y < col && land[x][y]) {
                    merge(idx, x * col + y);
                }
            }
            land[r][c] = true;
            if (r == 0) {
                merge(idx, top);
            }
            if (r == row - 1) {
                merge(idx, down);
            }
            if (find(top) == find(down)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
    int find(int x) {
        if (pa[x] != x) pa[x] = find(pa[x]);
        return pa[x];
    }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            pa[fx] = fy;
        }
    }
};