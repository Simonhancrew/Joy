impl Solution {
  pub fn find_longest_subarray(array: Vec<String>) -> Vec<String> {
      use std::collections::HashMap;
      let mut s = 0;
      let mut l = 0_i32;
      let mut r = 0_i32;
      let mut m = HashMap::new();
      m.insert(0, -1);

      array.iter().enumerate().for_each(|(i, x)| {
          if x.as_bytes().first().unwrap().is_ascii_alphabetic() {
              s += 1;
          } else {
              s -= 1;
          }
          if let Some(&v) = m.get(&s) {
              if i as i32 - v > r - l {
                  l = v;
                  r = i as i32;
              }
          } else {
              m.insert(s, i as i32);
          }
      });

      array[l as usize+1..r as usize +1].to_vec()
  }
}