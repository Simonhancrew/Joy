impl Solution {
  pub fn find_duplicates(mut nums: Vec<i32>) -> Vec<i32> {
    let (n, mut ans) = (nums.len(), Vec::new());
    for i in 0..n {
      let x = nums[i].abs() as usize;
      if nums[x - 1] > 0 {
        nums[x - 1] = -nums[x - 1];
      } else {
        ans.push(x as i32);
      }
    }
    ans
  }
}
