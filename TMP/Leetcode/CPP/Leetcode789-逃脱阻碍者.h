#include <vector>

using namespace std;

// 脑筋急转弯，能中中途捕获的捕获人一定能在结尾也捕获，只要算距离是小于等于的就可以了。


class Solution {
public:
    int get_dist(int x1,int y1,int x2,int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        for(auto gh:ghosts){
            if(get_dist(gh[0],gh[1],target[0],target[1]) <= abs(target[0]) + abs(target[1])){
                return false;
            }
        }
        return true;
    }
};