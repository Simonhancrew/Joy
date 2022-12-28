impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let (mut l, mut r) = (0, s.len() - 1);
        while l < r && s.as_bytes()[l] == s.as_bytes()[r] {
            let b = s.as_bytes()[l];
            while l <= r && s.as_bytes()[l] == b {
                l += 1;
            }
            while l <= r && s.as_bytes()[r] == b {
                r -= 1;
            }
        }
        (r + 1 - l) as i32
    }
}
