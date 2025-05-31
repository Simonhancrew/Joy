impl Solution {
  pub fn count_substrings(s: String, t: String) -> i32 {
    let mut cnt = 0;
    let n = s.len();
    let diff1 = |l: usize, r: usize, ll: usize| -> i32 {
      let ss = s.as_bytes();
      let tt = t.as_bytes();
      let mut flag = false;
      let mut j = ll;
      for i in l..=r {
        if ss[i] != tt[j] {
          if flag {
            return 0;
          }
          flag = true;
        }
        j += 1;
      }
      if flag {
        1
      } else {
        0
      }
    };

    let calcu = |l: usize, r: usize| -> i32 {
      let n = t.len();
      let mut cnt = 0;
      for i in 0..n - (r - l) {
        cnt += diff1(l, r, i);
      }
      cnt
    };

    for i in 0..n {
      for j in i..n {
        cnt += calcu(i, j);
      }
    }
    cnt
  }
}
