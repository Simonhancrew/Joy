impl Solution {
    fn dfs(f: &mut Vec<i64>, i: usize, questions: &Vec<Vec<i32>>) -> i64 {
        if (i >= questions.len()) {
            return 0;
        }
        let res = f[i];
        if (res != -1) {
            return res;
        }
        f[i] = Self::dfs(f, i + 1, questions).max(
            Self::dfs(f, i + 1 + questions[i][1] as usize, questions) + questions[i][0] as i64,
        );
        f[i]
    }
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let mut f = vec![-1i64; questions.len()];
        Self::dfs(&mut f, 0, &questions)
    }
}
