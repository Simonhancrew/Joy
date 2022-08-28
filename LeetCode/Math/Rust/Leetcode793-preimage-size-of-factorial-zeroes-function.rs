impl Solution {
    pub fn preimage_size_fzf(k: i32) -> i32 {
        let f = |mut x : i64| -> i64 {
            let mut res = 0;
            while x > 0 {
                res += x / 5;
                x /= 5;
            }
            res
        };

        let calcu = |k:i32| -> i64 {
            let (mut l,mut r) = (-1 as i64, 1e18 as i64);
            while l < r {
                let mid:i64 = (l + r + 1) >> 1;
                if f(mid) <= (k as i64) {
                    l = mid;
                }else {
                    r = mid - 1;
                }
            }
            r
        };

        (calcu(k) - calcu(k - 1)) as i32
    }
}