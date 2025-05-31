impl Solution {
  pub fn maximum_even_split(mut final_sum: i64) -> Vec<i64> {
    if final_sum & 1 != 0 {
      return vec![];
    }
    let (mut ans, mut i) = (vec![], 2i64);
    while final_sum >= i {
      ans.push(i);
      final_sum -= i;
      i += 2;
    }
    if final_sum != 0 {
      let n = ans.len();
      ans[n - 1] += final_sum;
    }
    ans
  }
}
