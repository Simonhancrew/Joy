impl Solution {
  pub fn defang_i_paddr(address: String) -> String {
    let mut res = String::new();
    for ch in address.chars() {
      if ch == '.' {
        res += "[.]";
      } else {
        res.push(ch);
      }
    }
    println!("{}", address);
    res
  }
}
