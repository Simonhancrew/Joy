impl Solution {
  pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
    let (mut res, n) = (vec![], nums.len());
    nums.sort_unstable();
    res.reserve(nums.len() / 3);
    for i in (0..n).step_by(3) {
      let (x, y, z) = (nums[i], nums[i + 1], nums[i + 2]);
      if z - x > k {
        return vec![];
      }
      res.push(vec![x, y, z]);
    }
    res
  }
}
