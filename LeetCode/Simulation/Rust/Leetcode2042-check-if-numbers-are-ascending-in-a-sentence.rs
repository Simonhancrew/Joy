impl Solution {
    pub fn are_numbers_ascending(s: String) -> bool {
        let (mut pre, mut i, n) = (-1, 0, s.len());
        while i < n {
            if s.as_bytes()[i] == b' ' {
                i += 1;
                continue;
            }
            let mut j = i;
            while j < n && s.as_bytes()[j] != b' ' {
                j += 1;
            }
            if s.as_bytes()[i] < b'0' || s.as_bytes()[i] > b'9' {
                i = j;
                continue;
            }
            let num = s[i..j].parse::<i32>().unwrap();
            if num <= pre {
                return false;
            }
            pre = num;
            i = j;
        }
        true
    }
}

