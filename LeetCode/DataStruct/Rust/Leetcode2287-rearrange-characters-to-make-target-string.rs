impl Solution {
    pub fn rearrange_characters(s: String, target: String) -> i32 {
        use std::collections::HashMap;
        let mut ans = i32::MAX;
        let mut map_t = HashMap::new();
        let mut map_s = HashMap::new();
        s.chars().for_each(|c| {
            map_s.entry(c).and_modify(|v| *v += 1).or_insert(1);
        });
        target.chars().for_each(|c| {
            map_t.entry(c).and_modify(|v| *v += 1).or_insert(1);
        });
        for (c, &n) in map_t.iter() {
            if let Some(&v) = map_s.get(c) {
                ans = ans.min(v / n);
            } else {
                return 0;
            }
        }
        ans
    }
}
