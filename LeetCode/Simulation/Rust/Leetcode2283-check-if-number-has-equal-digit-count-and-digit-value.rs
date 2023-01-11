impl Solution {
    pub fn digit_count(num: String) -> bool {
        let mut mp = vec![0;10];
        for c in num.as_bytes() {
            mp[(c - b'0') as usize] += 1; 
        }
        for i in 0..num.len() {
            let cnt = (num.as_bytes()[i] - b'0') as usize;
            if mp[i] != cnt {
                return false;
            }
        }
        true
    }
}
