use std::collections::HashMap;
impl Solution {
    pub fn count_balls(low_limit: i32, high_limit: i32) -> i32 {
        let (mut ans, mut mp) = (0, HashMap::new());
        let calcu = |mut x| {
            let mut res = 0;
            while x != 0 {
                res += x % 10;
                x /= 10;
            }
            res
        };
        for i in low_limit..=high_limit {
            mp.entry(calcu(i)).and_modify(|e| {*e += 1}).or_insert(1);
        }
        for (k,v) in &mp {
            ans = ans.max(*v);
        }
        ans
    }
}