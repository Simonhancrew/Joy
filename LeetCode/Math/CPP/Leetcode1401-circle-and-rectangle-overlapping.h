#include <utility>

using namespace std;

// 向量加减法在坐标上的应用

#define x first
#define y second
class Solution {
public:
    using PDD = pair<double, double>;
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        double recx = (x1 + x2) / 2.0, recy = (y1 + y2) / 2.0;
        // cout << recx << ' ' << recy << endl;
        PDD abs_core_dis = {std::abs(recx - (double)xCenter), std::abs(recy - (double)yCenter)};
        PDD rec_dis = {(double)x2 - recx, (double)y2 - recy};
        // cout << abs_core_dis.x << ' ' << abs_core_dis.y << endl;
        // cout << rec_dis.x << ' ' << rec_dis.y << endl;
        double nx = abs_core_dis.x - rec_dis.x;
        double ny = abs_core_dis.y - rec_dis.y;
        // cout << nx << ' ' << ny << endl;
        PDD sub_dis = {nx < 0 ? 0 : nx, ny < 0 ? 0 : ny};
        return sub_dis.x * sub_dis.x + sub_dis.y * sub_dis.y <= radius * radius;
    }
};