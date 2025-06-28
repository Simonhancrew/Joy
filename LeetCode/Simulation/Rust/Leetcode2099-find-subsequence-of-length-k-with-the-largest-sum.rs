impl Solution {
  pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let mut rec = (0..nums.len()).map(|x| x as i32).collect::<Vec<i32>>();
    rec.sort_by_key(|&x| -nums[x as usize]);
    rec.truncate(k as usize);
    rec.sort_unstable();
    rec.into_iter().map(|x| nums[x as usize]).collect::<Vec<i32>>()
  }
}
