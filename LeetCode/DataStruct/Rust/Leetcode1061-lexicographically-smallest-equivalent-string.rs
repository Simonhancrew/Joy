impl Solution {
  pub fn smallest_equivalent_string(s1: String, s2: String, base_str: String) -> String {
    let mut fa: Vec<u8> = (0..26).collect::<Vec<u8>>();
    let (s1, s2) = (s1.as_bytes(), s2.as_bytes());
    fn find(fa: &mut Vec<u8>, x: u8) -> u8 {
      if fa[x as usize] != x {
        fa[x as usize] = find(fa, fa[x as usize]);
      }
      fa[x as usize]
    }

    fn merge(fa: &mut Vec<u8>, x: u8, y: u8) {
      let (fx, fy) = (find(fa, x), find(fa, y));
      let (fx, fy) = (fx.max(fy), fy.min(fx));
      if fx == fy {
        return;
      }
      fa[fx as usize] = fy;
    }

    for i in 0..s1.len() {
      let (c1, c2) = (s1[i], s2[i]);
      merge(&mut fa, c1 - b'a', c2 - b'a');
    }

    let res: String = base_str
      .bytes()
      .map(|x| (find(&mut fa, x - b'a') + b'a') as char)
      .collect();
    res
  }
}
