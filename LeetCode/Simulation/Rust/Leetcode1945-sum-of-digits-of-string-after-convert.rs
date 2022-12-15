impl Solution {
    pub fn get_lucky(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let mut res = String::new();
        for c in s {
            let trans = c - b'a' + 1;
            res += &trans.to_string();
        }
        for i in 0..k {
            let mut ans = 0;
            for c in res.bytes() {
                ans += (c - b'0') as i32;
            }
            res = ans.to_string();
        }
        res.parse::<i32>().unwrap()
    }
}
