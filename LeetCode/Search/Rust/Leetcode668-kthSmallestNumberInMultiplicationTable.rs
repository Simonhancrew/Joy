impl Solution {
    pub fn find_kth_number(m: i32, n: i32, k: i32) -> i32 {
        let (mut l, mut r) = (0, m * n);
        let get = |mid: i32, m: i32, n: i32| -> i32 {
            let mut res = 0;
            for i in 1..=n {
                res += m.min(mid / i);
            }
            res
        };
        while l < r {
            let mid = (l + r) >> 1;
            if get(mid, m, n) >= k {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
