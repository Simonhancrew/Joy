impl Solution {
  pub fn kth_grammar(n: i32, k: i32) -> i32 {
      if n == 1 {
          return 0;
      }
      if k > (1 << (n - 2)) {
          return 1 ^ Self::kth_grammar(n, k - (1 << (n - 2)));
      }
      Self::kth_grammar(n - 1, k)
  }
}