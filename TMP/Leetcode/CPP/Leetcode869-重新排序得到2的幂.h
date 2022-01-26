#include <string>

using namespace std;

// 一般考虑2的幂的可以想想怎么枚举，遍历的长度不会很大

class Solution {
public:
    bool check(int i,int n){
        int mp1[10] = {0},mp2[10] = {0};
        for(auto ch : to_string(i)){
            mp1[ch - '0']++;
        }
        for(auto ch : to_string(n)){
            mp2[ch - '0']++;
        }
        for(int i = 0;i < 10;i++){
            if(mp1[i] != mp2[i]) return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n) {
        const int N = 1e9;
        for(int i = 1;i <= N;i *= 2){
            if(check(i,n)) return true;
        }
        return false;
    }
};