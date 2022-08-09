impl Solution {
    pub fn min_start_value(nums: Vec<i32>) -> i32 {
        let (mut ans,mut acc) = (1,0);
        for num in &nums {
            acc += num;
            let nag = 1 - acc;
            if nag > ans {
                ans = nag;
            }
        }
        ans
    }
}
