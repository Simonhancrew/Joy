impl Solution {
  pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
    let mut res = vec![];
    let k = k as usize;
    for i in (0..s.len()).step_by(k) {
      let mut tmp = s[i..(i + k).min(s.len())].to_string();
      tmp.extend(std::iter::repeat(fill).take(k - tmp.len()));
      res.push(tmp);
    }
    res
  }
}
