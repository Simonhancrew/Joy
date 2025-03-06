use std::collections::HashMap;
impl Solution {
    pub fn beautiful_subarrays(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut mp: HashMap<i32, i32> = HashMap::new();
        mp.insert(0, 1);
        let mut acc = 0;
        for x in &nums {
            acc ^= x;
            ans += *mp.entry(acc).or_default() as i64;
            *mp.entry(acc).or_default() += 1;
        }
        ans
    }
}