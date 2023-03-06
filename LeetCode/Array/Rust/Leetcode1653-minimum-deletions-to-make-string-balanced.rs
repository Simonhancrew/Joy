impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let n = s.len();
        let mut ss = vec![0;n + 1];
        for i in (0..n).rev() {
            ss[i] = ss[i + 1];
            if s.as_bytes()[i] == b'a' {
                ss[i] += 1;
            }
        }
        let mut res = ss[0];
        let mut l = 0;
        for i in 0..n {
            l += if s.as_bytes()[i] == b'b' {
                1
            } else {
                0
            };
            res = res.min(l + ss[i + 1]);
        }
        res
    }
}
