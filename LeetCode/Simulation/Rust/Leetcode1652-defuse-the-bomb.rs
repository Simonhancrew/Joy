impl Solution {
  pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
    let n = code.len();
    let mut ans = vec![0; n];
    if k == 0 {
      return ans;
    }
    for i in 0..n {
      if k > 0 {
        let mut acc = 0;
        for j in (i + 1)..=(i + k as usize) {
          acc += code[j % n];
        }
        ans[i] = acc;
      } else {
        let mut acc = 0;
        let ti = i as i32;
        let mut j = i as i32 - 1;
        while j >= ti + k {
          acc += code[(j + n as i32) as usize % n];
          j -= 1;
        }
        ans[i] = acc
      }
    }
    ans
  }
}
