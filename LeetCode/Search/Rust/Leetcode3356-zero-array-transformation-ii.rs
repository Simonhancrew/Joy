impl Solution {
  pub fn min_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> i32 {
    let (mut l, mut r) = (-1, queries.len() as i32 + 1);
    let check = |x: usize| -> bool {
      let mut pre = vec![0; nums.len() + 1];
      for q in &queries[0..x] {
        pre[q[0] as usize] += q[2];
        pre[q[1] as usize + 1] -= q[2];
      }
      for i in 0..nums.len() {
        pre[i] += if i > 0 { pre[i - 1] } else { 0 };
        if pre[i] < nums[i] {
          return false;
        }
      }
      true
    };
    while l + 1 < r {
      let mid = (l + r) >> 1;
      // println!("{}", mid);
      if check(mid as usize) {
        r = mid;
      } else {
        l = mid;
      }
    }
    if r as usize <= queries.len() {
      return r;
    }
    -1
  }
}
