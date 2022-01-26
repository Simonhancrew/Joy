impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {
        let (mut l,mut r) = (1 as i64,n as i64);
        while l < r{
            let mid = (l + r + 1) >> 1;
            let sum = (mid + 1) * mid / 2;
            if sum <= n as i64{
                l = mid;
            }else {
                r = mid - 1;
            }
        }
        l as i32
    }
}