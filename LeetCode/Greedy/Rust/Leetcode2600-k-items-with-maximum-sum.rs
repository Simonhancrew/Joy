impl Solution {
  pub fn k_items_with_maximum_sum(num_ones: i32, num_zeros: i32, num_neg_ones: i32, k: i32) -> i32 {
    num_ones.min(k) - (k - num_zeros - num_ones).max(0)
  }
}
