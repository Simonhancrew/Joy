impl Solution {
  pub fn min_elements(nums: Vec<i32>, limit: i32, goal: i32) -> i32 {
    let acc: i64 = nums.iter().map(|&x| x as i64).sum();
    let (goal, limit) = (goal as i64, limit as i64);
    if acc == goal {
      return 0;
    }
    let mut diff = (goal.max(acc) - goal.min(acc)).abs();
    // print!("acc: {}, goal: {}, diff: {}", acc, goal, diff);
    let res = (diff + limit - 1) / limit;
    res as i32
  }
}
