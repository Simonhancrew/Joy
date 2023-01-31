#include <vector>

using namespace std;

#define x first
#define y second
class Solution {
public:
    using PII = pair<int, int>;
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        PII l(0, 0), r(0, m - 1);
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if ((i == l.x && j == l.y) || (i == r.x && j == r.y)) {
                    if (!grid[i][j]) return false;
                } else {
                    if (grid[i][j]) return false;
                }
            }
            l.x++, r.x++;
            l.y++, r.y--;
        }
        return true;
    }
};
