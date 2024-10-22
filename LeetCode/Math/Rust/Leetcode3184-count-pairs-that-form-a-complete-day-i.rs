use std::collections::HashMap;
impl Solution {
    pub fn count_complete_day_pairs(hours: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut remain: HashMap<usize, i32> = HashMap::new();
        for &i in &hours {
            let r : usize = i as usize % 24;
            let complement = (24 - r) % 24;
            ans += remain.get(&complement).unwrap_or(&0);
            *remain.entry(r).or_insert(0) += 1;
        }
        ans
    }
}