#include <vector>

using namespace std;

// 用map超时了，数组就可以过

class Solution {
public:
    bool check(int n){
        vector<int> cnt(10);
        while(n){
            cnt[n % 10]++;
            n /= 10;
        }
        for(int i = 0;i < 10;i++){
            if(cnt[i] && cnt[i] != i) return 0;
        }
        return 1;
    }
    int nextBeautifulNumber(int n) {
        n += 1;
        while(!check(n)) n++;
        return n;
    }
};