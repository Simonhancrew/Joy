from typing import List
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row,col = [[0] * 10 for _ in range(9)],[[0] * 10 for _ in range(9)]
        box = [[[0] * 10 for _ in range(3)] for _ in range(3)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                t = ord(board[i][j]) - ord('0')
                row[i][t] += 1
                col[j][t] += 1
                box[i // 3][j // 3][t] += 1
                if row[i][t] > 1 or col[j][t] > 1 or box[i // 3][j // 3][t] > 1:
                    return False
        return True 