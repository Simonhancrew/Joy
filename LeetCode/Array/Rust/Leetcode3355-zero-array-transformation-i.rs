impl Solution {
  pub fn is_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> bool {
    let n = nums.len();
    let mut sub = vec![0; n + 1];
    for q in queries {
      let (l, r) = (q[0] as usize, q[1] as usize);
      sub[l] += 1;
      sub[r + 1] -= 1;
    }
    for i in 0..n {
      sub[i] += if i == 0 { 0 } else { sub[i - 1] };
      if sub[i] < nums[i] {
        return false;
      }
    }
    true
  }
}
