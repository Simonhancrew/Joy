impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        let mut cnt = 0;
        let mut x = num;
        while x != 0{
            x >>= 1;
            cnt += 1;
        }
        // rs的bit反是!
        !num & ((1 << cnt) - 1)
    }
}