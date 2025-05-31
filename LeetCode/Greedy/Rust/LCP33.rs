impl Solution {
  pub fn store_water(bucket: Vec<i32>, vat: Vec<i32>) -> i32 {
    let &mx = vat.iter().max().unwrap();
    if mx == 0 {
      return 0;
    }
    let mut ans = i32::MAX;
    for pour in 1..=mx {
      let mut add = 0;
      for (i, x) in vat.iter().enumerate() {
        add += 0.max((x + pour - 1) / pour - bucket[i]);
      }
      ans = ans.min(add + pour);
    }
    ans
  }
}
