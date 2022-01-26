#include <cstring>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0) return 0;
        int dp[m][n][maxMove + 1];
        memset(dp,0,sizeof dp);
        int res = 0;

        for(int i = 0;i < m;i++){
            dp[i][0][1]++;
            dp[i][n - 1][1]++;
        }
        for(int i = 0;i < n;i++){
            dp[0][i][1]++;
            dp[m - 1][i][1]++;
        }

        for(int k = 1;k <= maxMove;k++){
            for(int i = 0;i < m;i++){
                for(int j = 0;j < n;j++){
                    for(int d = 0;d < 4;d++){
                        int nx = i + dx[d],ny = j + dy[d];
                        if(nx >= 0 && nx < m && ny >= 0&& ny < n){
                            (dp[i][j][k] += dp[nx][ny][k - 1]) %= MOD;
                        } 
                    }
                }
            }
        }

        for(int i = 1;i <= maxMove;i++){
            (res += dp[startRow][startColumn][i]) %= MOD;
        }
        return res;
    }
};