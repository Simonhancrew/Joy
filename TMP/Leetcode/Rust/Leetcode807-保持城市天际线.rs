impl Solution {
    pub fn max_increase_keeping_skyline(grid: Vec<Vec<i32>>) -> i32 {
        let (mut n,mut m) = (grid.len(),grid[0].len());
        let (mut row,mut col) = (vec![0;n],vec![0;m]);
        for i in 0..n {
            for j in 0..m{
                row[i] = row[i].max(grid[i][j]);
                col[j] = col[j].max(grid[i][j]);
            }
        }
        let mut res = 0;
        for i in 0..n {
            for j in 0..m {
                res += row[i].min(col[j]) - grid[i][j];
            }
        }
        res
    }
}