impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut cnt = vec![vec![0; 10]; 10];
        let mut ans = 0;
        for d in dominoes {
            let [a, b] = if d[0] > d[1] {
                [d[1], d[0]]
            } else {
                [d[0], d[1]]
            };
            ans += cnt[a as usize][b as usize];
            cnt[a as usize][b as usize] += 1;
        }
        ans
    }
}
