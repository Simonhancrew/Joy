impl Solution {
    pub fn count_vowel_permutation(n: i32) -> i32 {
        let n = n as usize;
        let mut f = vec![vec![0 as i64;5];n + 1];
        const P:i64 = (1e9) as i64 + 7;
        for i in 0..5 {
            f[1][i] = 1;
        }
        for i in 2..=n {
            f[i][0] = f[i - 1][1];
            f[i][1] = f[i - 1][0] + f[i - 1][2];
            f[i][2] = f[i - 1][0] + f[i - 1][1] + f[i - 1][3] + f[i - 1][4];
            f[i][3] = f[i - 1][2] + f[i - 1][4];
            f[i][4] = f[i - 1][0];
            for j in 0..5 {
                f[i][j] %= P;
            }
        }
        let mut ans = 0 as i64;
        for i in 0..5 {
            ans += f[n][i];
        }
        (ans % P) as i32
    }
}