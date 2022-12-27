// rust simulation, greedy。遇到X就+3，ans += 1
impl Solution {
    pub fn minimum_moves(s: String) -> i32 {
        let (mut ans, n) = (0, s.len());
        let mut i = 0;
        while i < n {
            if s.as_bytes()[i] == b'O' {
                i += 1;
                continue;
            }
            i += 3;
            ans += 1;
        }
        ans
    }
}
