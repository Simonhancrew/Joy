use rand::{thread_rng, Rng};
use std::collections::{HashMap, HashSet};
struct Solution {
  mp: HashMap<i32, i32>,
  bd: i32,
}

impl Solution {
  fn new(n: i32, blacklist: Vec<i32>) -> Self {
    let m = blacklist.len();
    let bd = n - m as i32;
    let mut mp = HashMap::new();
    let mut st = HashSet::new();
    for x in &blacklist {
      if x >= &bd {
        st.insert(x);
      }
    }
    let mut it = bd;
    for x in &blacklist {
      if x < &bd {
        while st.contains(&it) {
          it += 1;
        }
        mp.entry(*x).or_insert(it);
        it += 1;
      }
    }
    Solution { mp, bd }
  }

  fn pick(&self) -> i32 {
    let mut rng = rand::thread_rng();
    let k = rng.gen_range(0, self.bd);
    if self.mp.contains_key(&k) {
      return *self.mp.get(&k).unwrap();
    }
    k
  }
}
