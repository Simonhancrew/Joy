// 要先手必胜，考虑当n % 4 == 0的时候，你无论取多少，对手都能取4 - x,最后一枚棋子必然是对手取走的

class Solution {
public:
    bool canWinNim(int n) {
        return n & 3;
    }
};