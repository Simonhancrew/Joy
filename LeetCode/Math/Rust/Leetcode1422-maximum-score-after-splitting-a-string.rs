impl Solution {
    pub fn max_score(s: String) -> i32 {
        let (mut rhs, mut lhs) = (0, 0);
        for &ch in s.as_bytes().iter() {
            if ch == b'1' {
                rhs += 1;
            }
        }
        let (mut res, n) = (0, s.len());
        let s = s.as_bytes();
        for i in 0..n - 1 {
            if s[i] == b'1' {
                rhs -= 1;
            } else {
                lhs += 1
            }
            res = res.max(lhs + rhs);
        }
        res
    }
}
