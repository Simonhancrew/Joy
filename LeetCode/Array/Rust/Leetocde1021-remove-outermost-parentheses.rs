impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let (mut res, n) = (String::new(), s.len());
        let mut i = 0;
        while i < n {
            let (mut j, mut cnt) = (i + 1, 1);
            while j < n && cnt != 0 {
                if &s[j..j + 1] == "(" {
                    cnt += 1;
                } else {
                    cnt -= 1;
                }
                j += 1;
            }
            res.push_str(&s[i + 1..j - 1]);
            i = j;
        }
        res
    }
}
