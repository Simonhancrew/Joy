use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
        let st = nums.iter().cloned().collect::<HashSet<i32>>();
        let tot = st.len();
        let (mut ans, mut l) = (0, 0);
        let mut mp = HashMap::new();
        for x in nums.iter() {
            mp.entry(x).and_modify(|z| *z += 1).or_insert(1);
            while mp.len() == tot {
                let tar = mp[&nums[l]];
                if let Some(val) = mp.get_mut(&nums[l]) {
                    *val -= 1;
                    if *val == 0 {
                        mp.remove(&nums[l]);
                    }
                    l += 1;
                }
            }
            ans += l;
        }
        ans as _ 
    }
}