var findDiagonalOrder = function (mat) {
    let [n, m, ans] = [mat.length, mat[0].length, []];
    for (let i = 0; i < m + n - 1; i++) {
        if (i & 1) {
            let x = i < m ? 0 : i - m + 1;
            let y = i < m ? i : m - 1;
            while (x < n && y >= 0) {
                ans.push(mat[x][y]);
                x++;
                y--;
            }
        } else {
            let x = i < n ? i : n - 1;
            let y = i < n ? 0 : i - n + 1;
            while (x >= 0 && y < m) {
                ans.push(mat[x][y]);
                x--;
                y++;
            }
        }
    }
    return ans;
};