use std::collections::HashMap;
impl Solution {
    pub fn similar_pairs(words: Vec<String>) -> i32 {
        let mut ans = 0;
        let mut mp = HashMap::new();
        for w in &words {
            let mut tmp = 0;
            for c in w.bytes() {
                tmp |= 1 << (c - b'a');
            }
            ans += mp.get(&tmp).unwrap_or(&0);
            *mp.entry(tmp).or_insert(0) += 1;
        }
        ans
    }
}
