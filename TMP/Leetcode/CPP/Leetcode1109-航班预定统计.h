#include <vector>

using namespace std;

// 差分，O(1)的拿到区间更改

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto bk:bookings){
            int l = bk[0],r = bk[1],w = bk[2];
            ans[l - 1] += w;
            if(r < n) ans[r] -= w; 
        }
        for(int i = 1;i < n;i++){
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};