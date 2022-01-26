#include <algorithm>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //经典容斥原理，求一个交集的长度，应用到二维
        int wid1 = ay2 - ay1,len1 = ax2 - ax1,wid2 = by2 - by1,len2 = bx2 - bx1;
        int wid3 = max(0,min(by2,ay2) - max(ay1,by1)),len3 = max(0,min(ax2,bx2) - max(ax1,bx1));
        return len1 * wid1 + len2 * wid2 - len3 * wid3;
    }
};