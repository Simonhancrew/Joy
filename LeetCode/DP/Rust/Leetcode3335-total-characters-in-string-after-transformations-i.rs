impl Solution {
    pub fn length_after_transformations(s: String, t: i32) -> i32 {
        let mut cnt = [0i64;26];
        let s = s.as_bytes();
        let MOD = 1e9 as i64 + 7;
        for &c in s {
            cnt[(c - b'a') as usize] += 1;
        }
        let t = t as usize;
        for i in 0..t {
            let mut tmp = [0;26];
            for j in 0..25 {
                tmp[j + 1] = cnt[j];
            }
            tmp[0] = cnt[25];
            tmp[1] = (cnt[25] + tmp[1]) % MOD;
            cnt = tmp;
        }
        let mut ans = 0;
        for x in cnt {
            ans = (ans as i64 + x) % MOD;
        }
        ans as _
    }
}
