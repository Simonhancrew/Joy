use std::mem;
impl Solution {
    pub fn one_edit_away(mut first: String, mut second: String) -> bool {
        let (mut n, mut m) = (first.len(), second.len());
        if (n as i32 - m as i32).abs() > 1 {
            return false;
        }
        if n > m {
            mem::swap(&mut first, &mut second);
            mem::swap(&mut n, &mut m);
        }
        let (mut i, mut j, mut cnt) = (0, 0, 0);
        while (i < n && j < m && cnt <= 1) {
            if first[i..i + 1] == second[j..j + 1] {
                i += 1;
                j += 1;
            } else {
                if n == m {
                    i += 1;
                    j += 1;
                    cnt += 1;
                } else {
                    j += 1;
                    cnt += 1;
                }
            }
        }
        cnt <= 1
    }
}
