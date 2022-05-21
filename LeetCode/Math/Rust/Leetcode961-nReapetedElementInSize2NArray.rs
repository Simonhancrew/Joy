#[allow(unused_imports)]
use rand::Rng;
use std::collections::HashSet;

impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let (n, mut rng) = (nums.len(), rand::thread_rng());
        loop {
            let (x, y) = (rng.gen_range(0, n), rng.gen_range(0, n));
            if x != y && nums[x] == nums[y] {
                return nums[x];
            }
        }
        -1
    }
}

/*

impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let mut st = HashSet::new();
        for x in &nums {
            if st.contains(x) {
                return *x;
            }
            st.insert(x);
        }
        -1
    }
}
*/
