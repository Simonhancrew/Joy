// 二维前缀和，数据范围很小，直接暴力枚举所有的正方形就可以了
// 用前缀和加速一下求取边长的操作
impl Solution {
    pub fn largest1_bordered_square(grid: Vec<Vec<i32>>) -> i32 {
        let (mut n, mut m) = (grid.len(), grid[0].len());
        let mut s = vec![vec![0;m + 1];n + 1];
        for i in 1..=n {
            for j in 1..=m {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1] as usize;
            }
        }
        let mn = n.min(m);
        let get = |x1: usize, y1: usize, x2: usize, y2: usize| -> usize {
            s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]
        };
        for length in (2..=mn).rev() {
            for i in 1..=(n + 1 - length) {
                for j in 1..=(m + 1 - length) {
                    let (a, b, c, d) = (i, j, i + length - 1, j + length - 1);
                    if get(a, b, c, d) - get(a + 1, b + 1, c - 1, d - 1) == 4 * (length - 1) {
                        return (length * length) as i32
                    }
                }
            }
        }
        if s[n][m] > 0 {
            return 1;
        }
        0
    }
}
