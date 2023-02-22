impl Solution {
    pub fn stone_game_ii(piles: Vec<i32>) -> i32 {
        let n = piles.len();
        let (mut s, mut f) = (vec![0;n + 1], vec![vec![0;n + 1];n + 2]);
        for i in 1..=n {
            s[i] = s[i - 1] + piles[i - 1];
        }
        for i in (1..=n).rev() {
            for j in 1..=n {
                let mut k = 1;
                while i + k - 1 <= n && k <= 2 * j {
                    f[i][j] = f[i][j].max(s[n] - s[i - 1] - f[i + k][k.max(j)]);
                    k += 1;
                }
            }
        }
        f[1][1]
    }
}
