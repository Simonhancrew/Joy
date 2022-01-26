#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


// 只能有一个起点，往两边扩大
// dp[i][j]从i到j变成同色砖块需要的最小操作次数
// 相邻的块一定不同色，所以扩充的时候咋样都要+1

const int N = 5e3 + 10;

int dp[N][N],n,x,a[N],cnt;

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> x;
        if(a[cnt] != x){
            a[++cnt] = x;
        }
    }
    
    for(int len = 2;len <= cnt;len++){
        for(int l = 1;l + len - 1 <= cnt;l++){
            int r = l + len - 1;
            if(a[l] == a[r]) dp[l][r] = dp[l + 1][r - 1] + 1;
            else dp[l][r] = min(dp[l + 1][r],dp[l][r - 1]) + 1;
        }
    }
    cout << dp[1][cnt] << endl;
}