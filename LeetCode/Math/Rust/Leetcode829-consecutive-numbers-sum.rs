impl Solution {
    pub fn consecutive_numbers_sum(n: i32) -> i32 {
        let (n,mut b) = (n * 2,1);
        let mut res = 0;
        while b <= n / b {
            if n % b == 0{
                if (n / b - b + 1) % 2 == 0 {
                    res += 1;
                }
            }
            b += 1;
        }
        res
    }
}