#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// 跨象限的点看作环形数组，这里只用遍历一次，直接复制加到最后

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int st = 0;
        vector<double> degree;
        for(auto point : points) {
            if(point[0] == location[0] && point[1] == location[1]){
                st++;
                continue;
            }
            int dx = point[0] - location[0],dy = point[1] - location[1];
            double dg = atan2(dy,dx);
            degree.push_back(dg);
        }
        sort(degree.begin(),degree.end());
        int n = degree.size();
        for(int i = 0;i < n;i++){
            degree.push_back(degree[i] + 2 * M_PI);
        }
        int cnt = 0;
        double angled = angle * M_PI / 180;
        for(int i = 0,j = 0;i < n;i++){
            while(j < degree.size() && degree[j] - degree[i] <= angled) {
                j++;
            }
            cnt = max(cnt,j - i);
        }
        return cnt + st;
    }
};