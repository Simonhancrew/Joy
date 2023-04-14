impl Solution {
    pub fn camel_match(queries: Vec<String>, pattern: String) -> Vec<bool> {
        let n = queries.len();
        let mut ans = vec![false;n];
        let check = |s:&str| -> bool {
            if s.len() < pattern.len() {
                return false;
            }
            let s = s.as_bytes();
            let mut j = 0;
            for i in 0..s.len() {
                if j < pattern.len() && s[i] == pattern.as_bytes()[j] {
                    j += 1;
                } else if s[i] < b'a' || s[i] > b'z' {
                    return false;
                }
            }
            j >= pattern.len()
        };
        for i in 0..n {
            ans[i] = check(&queries[i]);
        }
        ans
    }
}
