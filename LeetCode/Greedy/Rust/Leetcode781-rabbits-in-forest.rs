use std::collections::HashMap;
impl Solution {
  pub fn num_rabbits(answers: Vec<i32>) -> i32 {
    let mut mp: HashMap<i32, i32> = HashMap::new();
    for x in answers {
      let v = mp.entry(x).or_default();
      *v += 1;
    }
    let mut ans = 0;
    for (&k, &v) in mp.iter() {
      if k == 0 {
        ans += v;
        continue;
      }
      ans += (v + k) / (k + 1) * (k + 1);
    }
    ans
  }
}
