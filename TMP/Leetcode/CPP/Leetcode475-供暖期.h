#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(int len,vector<int> &h,vector<int>& ht){
        for(int i = 0,j = 0;i < h.size();i++){
            while(j < ht.size() && abs(h[i] - ht[j]) > len) {
                j++;
            }
            if(j >= ht.size()) return false;
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int l = 0,r = max(*max_element(houses.begin(),houses.end()),*max_element(heaters.begin(),heaters.end()));
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid,houses,heaters)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
private:
    vector<int> h,ht;
};