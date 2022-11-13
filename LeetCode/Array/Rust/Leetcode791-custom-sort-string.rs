impl Solution {
  pub fn custom_sort_string(order: String, s: String) -> String {
      let mut tab = [26; 26];
      order.bytes().enumerate().for_each(|(i, c)| {
          tab[c as usize - 'a' as usize] = i;
      });
      let mut s: Vec<char> = s.chars().collect();
      s.sort_unstable_by(|a, b| usize::cmp(
          &tab[*a as usize - 'a' as usize],
          &tab[*b as usize - 'a' as usize]));
      s.into_iter().collect()
  }
}