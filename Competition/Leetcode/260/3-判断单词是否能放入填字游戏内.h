#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(),n = board[0].size(),k = word.size();
        // 遍历行，看看能不能填入word，正序倒序分别判断
        for(int i = 0;i < m;i++){
            auto row = board[i];
            for(int j = 0;j < n;j++){
                if(row[j] == '#') continue;
                int j0 = j,ok1 = 1,ok2 = 1;
                while(j < n && row[j] != '#'){
                    if(j - j0 >= k || (row[j] != ' ' && row[j] != word[j - j0])){
                        ok1 = false;
                    }
                    if(j - j0 >= k || (row[j] != ' ' && row[j] != word[k - 1 - j + j0])){
                        ok2 = false;
                    }
                    j++;
                }
                if((ok1 || ok2) && (j - j0) == k) return true;
            }
        }
        // 遍历一下列，同样的操作
        for(int j = 0;j < n;j++){
            for(int i = 0;i < m;i++){
                if(board[i][j] == '#') continue;
                int i0 = i,ok1 = 1,ok2 = 1;
                while(i < m && board[i][j] != '#'){
                    if(i - i0 >= k || (board[i][j] != ' ' && board[i][j] != word[i - i0])){
                        // if(j == 1) cout << i << ' ' << word[i - i0] << endl;
                        ok1 = false;
                    }
                    if(i - i0 >= k || (board[i][j] != ' ' && board[i][j] != word[k - 1 - i + i0])){
                        ok2 = false;
                    }
                    i++;
                }
                if((ok1 || ok2) && (i - i0) == k) return true;
            }
        }
        return false;
    }
};