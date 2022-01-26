#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n,t;
int cnt[N];

// 直接枚举公约数就可以了
// 记最小公约数为i，记录的时候用桶记录每个数有多少个，最后统计的时候直接按照i,2i,3i,4i的样子统计
// 

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> t;
        cnt[t]++;
    }
    // 最少是1
    int res = 1;
    for(int i = 2;i < N;i++){
        int t = 0;
        for(int j = i;j < N;j += i){
            t += cnt[j];
        }
        res = max(res,t);
    }
    cout << res << endl;
}