impl Solution {
    pub fn magical_string(n: i32) -> i32 {
        let mut s = String::from("122");
        let (mut i, mut k) = (2, 1);
        while s.len() < n as usize {
            let r = (s.as_bytes()[i] - b'0') as usize;
            for j in 0..r {
                s.push((b'0' + k as u8) as char);
            }
            i += 1;
            k = 3 - k;
        }
        let mut res = 0;
        for j in 0..n as usize {
            if s.as_bytes()[j] == b'1' {
                res += 1;
            } 
        }
        res
    }
}
