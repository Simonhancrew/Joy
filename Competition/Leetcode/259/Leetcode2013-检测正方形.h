#include <map>
#include <vector>

using namespace std;

class DetectSquares {
public:
    map<int,map<int,int>> mp;
    DetectSquares() {

    }
    
    void add(vector<int> const &point) {
        int x = point[0],y = point[1];
        mp[x][y]++;
    }
    
    int get(int x,int y) {
        if(!mp.count(x) || !mp[x].count(y)) return 0;
        return mp[x][y];
    }


    int count(vector<int> const &point) {
        int x = point[0],y = point[1];
        int ans = 0;
        for(auto &[y1,c] : mp[x]) {
            if(y1 != y) {
                ans += c * get(x + abs(y1 - y),y1) * get(x + abs(y1 - y),y);
                ans += c * get(x - abs(y1 - y),y1) * get(x - abs(y1 - y),y);
            }
        }
        return ans;
    }
};