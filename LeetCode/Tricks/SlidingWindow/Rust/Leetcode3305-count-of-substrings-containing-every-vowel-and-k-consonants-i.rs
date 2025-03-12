use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn count_of_substrings(word: String, k: i32) -> i32 {
        let st: HashSet<char> = "aeiou".chars().collect();
        let f = |s: &str, k: i32| -> i32 {
            let (mut ans, mut l) = (0, 0 as usize);
            let mut cnt = 0;
            let mut mp: HashMap<char,i32> = HashMap::new();
            for c in s.chars() {
                if st.contains(&c) {
                    mp.entry(c).and_modify(|x| *x += 1).or_insert(1);
                } else {
                    cnt += 1;
                }
                while cnt >= k && mp.len() == 5 {
                    if st.contains(&(s.as_bytes()[l] as char)) {
                        mp.entry(s.as_bytes()[l] as char).and_modify(|x| *x -= 1);
                        if mp[&(s.as_bytes()[l] as char)] == 0 {
                            mp.remove(&(s.as_bytes()[l] as char));
                        }
                    } else {
                        cnt -= 1;
                    }
                    l += 1;
                }
                ans += l as i32;
            }
            ans
        };
        f(&word, k) - f(&word, k + 1)
    }
}