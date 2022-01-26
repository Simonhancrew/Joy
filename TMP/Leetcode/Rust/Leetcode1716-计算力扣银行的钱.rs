impl Solution {
    pub fn total_money(n: i32) -> i32 {
        let (mut ans,mut cnt) = (0,1);
        for i in 0..n{
            if i != 0 && i % 7 == 0 {
                cnt += 1;
            }
            ans += (cnt + i % 7);
        }
        ans
    }
}