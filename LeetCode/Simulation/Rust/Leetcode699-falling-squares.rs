impl Solution {
    pub fn falling_squares(positions: Vec<Vec<i32>>) -> Vec<i32> {
        let n = positions.len();
        let mut ans = vec![0;n];
        for i in 0..n {
            let (l1,r1) = (positions[i][0],positions[i][0] + positions[i][1] - 1);
            ans[i] = positions[i][1];
            for j in 0..i {
                let (l2,r2) = (positions[j][0],positions[j][1] + positions[j][0] - 1);
                if r1 >= l2 && r2 >= l1 {
                    ans[i] = ans[i].max(ans[j] + positions[i][1]);
                }
            }
        }
        for i in 1..n {
            ans[i] = ans[i].max(ans[i - 1]);
        }
        ans
    }
}