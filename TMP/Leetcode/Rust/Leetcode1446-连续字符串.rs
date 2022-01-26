impl Solution {
    pub fn max_power(s: String) -> i32 {
        let (mut res,mut i,mut j) = (0,0,0);
        let s = s.as_bytes();
        while i < s.len() as i32{
            while j < s.len() as i32 && s[i as usize] == s[j as usize]{
                j += 1;
            }
            res = res.max(j - i);
            i = j;
        }
        res
    }
}