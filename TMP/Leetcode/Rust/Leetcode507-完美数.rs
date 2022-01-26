impl Solution {
    pub fn check_perfect_number(num: i32) -> bool {
        let mut ans = 0;
        let mut i = 1;
        while i <= num / i {
            if num % i == 0{
                if i < num {
                    ans += i;
                }
                if num / i < num && i != num / i {
                    ans += num / i
                }
            }
            i += 1;
        }
        ans == num
    }
}