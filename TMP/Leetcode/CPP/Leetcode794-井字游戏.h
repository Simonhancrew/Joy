#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cntx = 0,cnto = 0;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(board[i][j] == 'X') cntx++;
                else if(board[i][j] == 'O') cnto++;
            }
           
        }
        if(cnto != cntx && cnto != cntx - 1) return false;
        if(check(board,'X') && cntx != cnto + 1) return false;
        if(check(board,'O') && cnto != cntx) return false;
        return true;
    }
    bool check(vector<string> board,char t){
        for(int i = 0;i < 3;i++){
            if(board[i][0] == t && board[i][1] == t && board[i][2] == t) return true;
            if(board[0][i] == t && board[1][i] == t && board[2][i] == t) return true;
        }
        if(board[0][0] == t && board[1][1] == t && board[2][2] == t) return true;
        if(board[2][0] == t && board[1][1] == t && board[0][2] == t) return true;
        return false;
    }
};