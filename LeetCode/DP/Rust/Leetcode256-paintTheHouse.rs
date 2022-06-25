impl Solution {
    pub fn min_cost(costs: Vec<Vec<i32>>) -> i32 {
        let n = costs.len();
        let mut f = vec![vec![0;3];n + 1];
        for i in 1..=n {
            for j in 0..3 {
                if j == 0 {
                    f[i][j] = f[i - 1][1].min(f[i - 1][2]);
                }
                if j == 1 {
                    f[i][j] = f[i - 1][0].min(f[i - 1][2]);
                }
                if j == 2 {
                    f[i][j] = f[i - 1][0].min(f[i - 1][1]);
                }
                f[i][j] += costs[i - 1][j];
            }
        }
        f[n][0].min(f[n][1].min(f[n][2]))
    }
}