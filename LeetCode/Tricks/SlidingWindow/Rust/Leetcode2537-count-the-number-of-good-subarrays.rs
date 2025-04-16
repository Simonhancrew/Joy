use std::collections::HashMap;
impl Solution {
    pub fn count_good(nums: Vec<i32>, k: i32) -> i64 {
        let mut mp = HashMap::new();
        let (mut ans, mut l, mut pairs) = (0i64, 0usize, 0i32);
        for r in 0..nums.len() {
            if let Some(&x) = mp.get(&nums[r]) {
                pairs += x;
            }
            mp.entry(nums[r]).and_modify(|val| *val += 1).or_insert(1);
            while pairs >= k {
                mp.entry(nums[l]).and_modify(|val| *val -= 1);
                pairs -= mp[&nums[l]];
                l += 1;
            }
            ans += l as i64;
        }
        ans
    }
}
