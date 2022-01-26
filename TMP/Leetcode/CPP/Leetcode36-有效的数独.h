#include <vector>
using namespace std;

class Solution {
public:
    int row[9][10] = {0},col[9][10] = {0},box[3][3][10] = {0};
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.') continue;
                int u = board[i][j] - '0';
                row[i][u]++,col[j][u]++,box[i / 3][j / 3][u]++;
                if(row[i][u] > 1 || col[j][u] > 1 || box[i / 3][j / 3][u] > 1) return false;
            }
        }
        return true;
    }
};