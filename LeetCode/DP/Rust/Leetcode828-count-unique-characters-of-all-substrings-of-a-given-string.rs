impl Solution {
    pub fn unique_letter_string(s: String) -> i32 {
        let n = s.len();
        let (mut l,mut r,mut last) = (vec![0;n],vec![0;n],vec![-1;26]);
        let sb = s.as_bytes();
        for i in 0..n {
            l[i] = last[(sb[i] - b'A') as usize];
            last[(sb[i] - b'A') as usize] = i as i32;
        }
        last = vec![n as i32;26];
        for i in (0..n).rev() {
            r[i] = last[(sb[i] - b'A') as usize];
            last[(sb[i] - b'A') as usize] = i as i32;
        }
        let mut ans = 0;
        for i in 0..n {
            ans += (i as i32 - l[i]) * (r[i] - i as i32)
        }
        ans
    }
}
