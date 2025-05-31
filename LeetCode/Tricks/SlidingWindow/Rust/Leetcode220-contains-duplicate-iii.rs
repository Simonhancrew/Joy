use std::collections::BTreeMap;
impl Solution {
  pub fn contains_nearby_almost_duplicate(nums: Vec<i32>, index_diff: i32, value_diff: i32) -> bool {
    let mut mp: BTreeMap<i32, usize> = BTreeMap::new();
    let n = nums.len();
    let index_diff = index_diff as usize;
    for r in 0..n {
      let lower = nums[r] - value_diff;
      if let Some((key, _)) = mp.range(lower..=nums[r] + value_diff).next() {
        return true;
      }
      *mp.entry(nums[r]).or_insert(0) += 1;
      if r >= index_diff {
        let tar = nums[r - index_diff];
        let count = mp.get_mut(&tar).unwrap();
        *count -= 1;
        if *count == 0 {
          mp.remove(&tar);
        }
      }
    }
    false
  }
}
