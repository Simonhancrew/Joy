use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn count_of_substrings(word: String, k: i32) -> i64 {
        let st: HashSet<u8> = "aeiou".as_bytes().iter().cloned().collect();
        let f = |s: &[u8], k: i32|-> i64 {
            let mut mp = HashMap::new();
            let (mut l, mut ans, mut cnt) = (0 as usize, 0 as i64, 0);
            for c in s {
                if st.contains(c) {
                    mp.entry(c).and_modify(|x| *x += 1).or_insert(1);
                } else {
                    cnt += 1;
                }
                while cnt >= k && mp.len() == 5 {
                    if st.contains(&s[l]) {
                        mp.entry(&s[l]).and_modify(|x| *x -= 1);
                        if mp[&s[l]] == 0 {
                            mp.remove(&s[l]);
                        }
                    } else {
                        cnt -= 1;
                    }
                    l += 1;
                }
                ans += l as i64;
            }
            ans
        };
        f(word.as_bytes(), k) - f(word.as_bytes(), k + 1)
    }
}