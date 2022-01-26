impl Solution {
    pub fn num_friend_requests(ages: Vec<i32>) -> i32 {
        let n = ages.len();
        let mut ans = (n * n) as i32;
        let mut cnt = vec![0;121];
        for age in ages.iter(){
            cnt[*age as usize] += 1;
        }
        for i in 1..=120{
            for j in 1..=120{
                if j > i || 2 * j <= i + 14 {
                    ans -= cnt[i] * cnt[j];
                }else if j == i{
                    ans -= cnt[i];
                }
            }
        }
        ans
    }
}