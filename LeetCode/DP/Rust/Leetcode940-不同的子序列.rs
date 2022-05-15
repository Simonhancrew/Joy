impl Solution {
    pub fn distinct_subseq_ii(s: String) -> i32 {
        let (n, MOD) = (s.len(), 1e9 as i32 + 7);
        let mut f = vec![vec![0; 26]; n + 1];
        for (i, x) in s.bytes().enumerate() {
            f[i + 1][(x - b'a') as usize] = 1;
            for j in 0..26 {
                f[i + 1][(x - b'a') as usize] = (f[i + 1][(x - b'a') as usize] + f[i][j]) % MOD;
                if (x - b'a') as usize != j {
                    f[i + 1][j] = f[i][j];
                }
            }
        }
        let mut res = 0;
        for x in &f[n] {
            res = (res + x) % MOD;
        }
        res
    }
}
