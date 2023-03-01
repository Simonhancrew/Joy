impl Solution {
    pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = grid.len();
        let mut res = vec![vec![0;n - 2];n - 2];
        for i in 0..n-2 {
            for j in 0..n-2 {
                for x in i..n.min(i + 3) {
                    for y in j..n.min(j + 3) {
                        res[i][j] = res[i][j].max(grid[x][y]);
                    }
                }
            }
        }
        res
    } 
}
