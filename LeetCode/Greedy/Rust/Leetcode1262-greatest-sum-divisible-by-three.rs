impl Solution {
  pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
      let (mut s1, mut s2) = (1e5 as i32, 1e5 as i32);
      let (mut t1, mut t2) = (1e5 as i32, 1e5 as i32);
      let mut sum = 0;
      for &x in nums.iter() {
          sum += x;
          if x % 3 == 1 {
              if s1 >= x {
                  s2 = s1;
                  s1 = x;
              } else if s2 >= x {
                  s2 = x;
              }
          } else if x % 3 == 2 {
              if t1 >= x {
                  t2 = t1;
                  t1 = x;
              } else if t2 >= x {
                  t2 = x;
              }
          }
      }
      if sum % 3 == 0 {
          return sum;
      }
      if sum % 3 == 1 {
          return (sum - s1).max(sum - t1 - t2);
      }
      (sum - s1 - s2).max(sum - t1)
  }
}
