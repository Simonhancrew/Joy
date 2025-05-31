impl Solution {
  pub fn generate_the_string(n: i32) -> String {
    let n = n as usize;
    if n % 2 == 0 {
      return "a".repeat(n - 1) + "b";
    }
    if n == 1 {
      return String::from("a");
    }
    "a".repeat(n - 2) + "b" + "c"
  }
}
