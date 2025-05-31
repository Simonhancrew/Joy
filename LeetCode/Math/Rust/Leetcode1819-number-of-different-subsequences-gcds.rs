impl Solution {
  pub fn count_different_subsequence_gc_ds(nums: Vec<i32>) -> i32 {
    let N = 2e5 as i32 + 10;
    let mut mp = vec![false; N as usize];
    let mut mx = 0;
    nums.iter().for_each(|v| {
      mp[*v as usize] = true;
      mx = mx.max(*v);
    });
    fn gcd(a: i32, b: i32) -> i32 {
      if b == 0 {
        return a;
      }
      gcd(b, a % b)
    }
    let mut ans = 0;
    for i in 1..=mx {
      let (mut g, mut j) = (0, 0);
      while j <= mx && g != i {
        if mp[j as usize] {
          g = gcd(g, j);
        }
        j += i;
      }
      if g == i {
        ans += 1
      }
    }
    ans
  }
}
