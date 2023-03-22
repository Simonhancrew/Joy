impl Solution {
    pub fn best_team_score(scores: Vec<i32>, ages: Vec<i32>) -> i32 {
        let n = ages.len();
        let mut rec = vec![];
        for i in 0..n {
            rec.push(vec![ages[i], scores[i]]);
        }
        rec.sort();
        let mut f = vec![0;n];
        let mut res = 0;
        for i in 0..n {
            f[i] = rec[i][1];
            for j in 0..i {
                if rec[i][1] >= rec[j][1] {
                    f[i] = f[i].max(f[j] + rec[i][1]);
                }
            }
            res = res.max(f[i]);
        }
        res
    }
}
