use std::collections::HashMap;
impl Solution {
    pub fn two_out_of_three(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>) -> Vec<i32> {
        let mut mp = HashMap::new();
        for x in &nums1 {
            mp.entry(x).and_modify(|val| *val |= 1).or_insert(1); 
        }
        for x in &nums2 {
            mp.entry(x).and_modify(|val| *val |= 2).or_insert(2);
        }
        for x in &nums3 {
            mp.entry(x).and_modify(|val| *val |= 4).or_insert(4);
        }
        let mut ans = vec![];
        for (&key, val) in mp.iter() {
            if val & (val - 1) != 0 {
                ans.push(*key);
            }
        }
        ans
    }
}
