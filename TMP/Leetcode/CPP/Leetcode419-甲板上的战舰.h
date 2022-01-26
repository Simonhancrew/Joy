#include <vector>

using namespace std;

#if 0
class Solution {
public:
    vector<vector<int>> st;
    int n,m;
    int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
    int countBattleships(vector<vector<char>>& board) {
        n = board.size(),m = board[0].size();
        int ans = 0;
        st = vector<vector<int>> (n,vector<int> (m,0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(board[i][j] == '.' || st[i][j] == 1) continue;
                ans++;
                dfs(board,i,j);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board,int x,int y) {
        if(board[x][y] == '.') return;
        st[x][y] = 1;
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && st[nx][ny] == 0 && board[nx][ny] == 'X') dfs(board,nx,ny);
        }
    }
};
#endif
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0,n = board.size(),m = board[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++) {
                if(i > 0 && board[i - 1][j] == 'X') continue;
                if(j > 0 && board[i][j - 1] == 'X') continue;
                if(board[i][j] == 'X') ++ans;
            }
        }
        return ans;
    }
};