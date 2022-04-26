impl Solution {
    pub fn projection_area(grid: Vec<Vec<i32>>) -> i32 {
        let (mut l,mut r,mut d,n) = (0,0,0,grid.len());
        for i in 0..n {
            let (mut tl,mut tr) = (0,0);
            for j in 0..n {
                if grid[i][j] != 0 {
                    d += 1;
                }
                tl = tl.max(grid[i][j]);
                tr = tr.max(grid[j][i]);
            }
            l += tl;
            r += tr;
        }
        return l + d + r;
    }
}