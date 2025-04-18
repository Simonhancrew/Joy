use std::collections::HashMap;
impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut mp: HashMap<i32, i32> = HashMap::new();
        let mut ans = 0i64;
        for i in 0..nums.len() {
            let tar = i as i32 - nums[i];
            let val = mp.entry(tar).or_default();
            ans += (i - *val as usize) as i64;
            *val += 1;
        }
        ans
    }
}