impl Solution {
  pub fn find_matrix(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut cnt: Vec<i32> = vec![0; nums.len() + 1];
    let mut res: Vec<Vec<i32>> = Vec::new();
    for x in nums {
      let cur = &mut cnt[x as usize];
      if *cur as usize == res.len() {
        res.push(vec![]);
      }
      res[*cur as usize].push(x);
      *cur += 1;
    }
    res
  }
}
