impl Solution {
    pub fn order_of_largest_plus_sign(n: i32, mines: Vec<Vec<i32>>) -> i32 {
        let (mut f, mut g) = (vec![vec![0;n as usize];n as usize], vec![vec![true;n as usize];n as usize]);
        for x in &mines {
            g[x[0] as usize][x[1] as usize] = false;
        }
        let n = n as usize;
        for i in 0..n {
            let mut s = 0;
            for j in 0..n {
                if g[i][j] {
                    s += 1;
                } else {
                    s = 0;
                }
                f[i][j] = s;
            }
        }

        for i in 0..n {
            let mut s = 0;
            for j in (0..n).rev() {
                if g[i][j] {
                    s += 1;
                } else {
                    s = 0;
                }
                f[i][j] = f[i][j].min(s);
            }
        }

        for j in 0..n {
            let mut s = 0;
            for i in 0..n {
                if g[i][j] {
                    s += 1;
                } else {
                    s = 0;
                }
                f[i][j] = f[i][j].min(s);
            }
        }

        for j in 0..n {
            let mut s = 0;
            for i in (0..n).rev() {
                if g[i][j] {
                    s += 1;
                } else {
                    s = 0;
                }
                f[i][j] = f[i][j].min(s);
            }
        }
        let mut res = 0;
        for i in 0..n {
            for j in 0..n {
                res = res.max(f[i][j]);
            }
        }
        res
    }
}
