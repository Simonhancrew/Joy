impl Solution {
    pub fn sum_subseq_widths(mut nums: Vec<i32>) -> i32 {
        let (n, P) = (nums.len(), 1e9 as i32 + 7);
        let mut p = vec![0;n + 1];
        p[0] = 1;
        for i in 1..=n {
            p[i] = p[i - 1] * 2 % P;
        }
        nums.sort();
        let mut res = 0;
        for i in 0..n {
            res = ((res as i64 + nums[i] as i64 * p[i] as i64 - nums[i] as i64 * p[n - i - 1] as i64) % P as i64) as i32;
        }
        res
    }
}
