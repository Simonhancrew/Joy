impl Solution {
  pub fn divisor_substrings(num: i32, k: i32) -> i32 {
    let s = num.to_string();
    let mut res = 0;
    for i in (k - 1) as usize..s.len() {
      if let Ok(cur) = (&s[i - k as usize + 1..i + 1]).parse::<i32>() {
        print!("{cur}");
        if cur != 0 && num % cur == 0 {
          res += 1;
        }
      }
    }
    res
  }
}
