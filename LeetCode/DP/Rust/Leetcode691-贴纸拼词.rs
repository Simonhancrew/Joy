impl Solution {
    pub fn min_stickers(stickers: Vec<String>, target: String) -> i32 {
        let n = target.len();
        let mut f = vec![-1; 1 << n];
        let res = Solution::dp(&stickers, &target, &mut f, 0);
        if res >= n as i32 + 1 {
            return -1;
        }
        res
    }

    pub fn dp(stickers: &Vec<String>, target: &String, f: &mut Vec<i32>, st: usize) -> i32 {
        if f[st] != -1 {
            return f[st];
        }
        if st == (1 << target.len()) - 1 {
            return 0;
        }
        f[st] = target.len() as i32 + 1;
        for s in stickers {
            let mut t = st;
            let mut cnt = vec![0; 26];
            for c in s.bytes() {
                cnt[(c - 'a' as u8) as usize] += 1;
            }
            for (i, c) in target.bytes().enumerate() {
                if (t >> i) & 1 == 0 && cnt[(c - 'a' as u8) as usize] > 0 {
                    t += 1 << i;
                    cnt[(c - 'a' as u8) as usize] -= 1;
                }
            }
            if t != st {
                f[st] = f[st].min(Solution::dp(stickers, target, f, t) + 1);
            }
        }
        f[st]
    }
}
