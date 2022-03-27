impl Solution {
    pub fn has_alternating_bits(mut n: i32) -> bool {
        let mut pre = n & 1;
        n >>= 1;
        while n != 0 {
            if pre == (n & 1) {
                return false;
            }
            pre = n & 1;
            n >>= 1;
        }
        true
    }
}