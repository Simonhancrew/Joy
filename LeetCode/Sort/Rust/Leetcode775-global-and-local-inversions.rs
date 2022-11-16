impl Solution {
    pub fn is_ideal_permutation(nums: Vec<i32>) -> bool {
        let (mut lmin, n) = (nums[nums.len() - 1], nums.len());
        for i in (1..n - 1).rev() {
            if nums[i - 1] > lmin {
                return false;
            }
            lmin = lmin.min(nums[i])
        }
        true
    }
}
