impl Solution {
    pub fn k_inverse_pairs(n: i32, k: i32) -> i32 {
        let mut f = vec![vec![0;k as usize + 1];n as usize + 1];
        f[1][0] = 1;
        let MOD = 1e9 as i64 + 7;
        for i in 2..=n{
            let mut s:i64 = 0;
            for j in 0..=k{
                s += f[i as usize - 1][j as usize];
                if (j >= i){
                    s -= f[i as usize- 1][j as usize - i as usize];
                }
                f[i as usize][j as usize] = s % MOD;
            }
        }
        f[n as usize][k as usize] as i32
    }
}