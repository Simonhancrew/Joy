impl Solution {
    pub fn moves_to_make_zigzag(nums: Vec<i32>) -> i32 {
        let mut res = vec![0;2];
        let n = nums.len();
        for i in 0..n {
            let lhs = if i > 0 {
                nums[i - 1]
            } else {
                i32::MAX
            };
            let rhs = if i < n - 1 {
                nums[i + 1]
            } else {
                i32::MAX
            };
            res[i % 2] += 0.max(nums[i] - rhs.min(lhs) + 1);
        }
        res[0].min(res[1])
    }
}
