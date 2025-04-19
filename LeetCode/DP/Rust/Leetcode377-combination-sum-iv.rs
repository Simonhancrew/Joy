impl Solution {
    pub fn combination_sum4(mut nums: Vec<i32>, target: i32) -> i32 {
        let mut f = vec![-1; target as usize + 1];
        nums.sort_unstable();
        fn dfs(nums: &[i32], f: &mut Vec<i32>, tar: usize) -> i32 {
            if (tar == 0) {
                return 1;
            }
            if f[tar] != -1 {
                return f[tar as usize];
            }
            f[tar] = 0;
            for &x in nums.iter() {
                if x > tar as i32 {
                    break;
                }
                f[tar] += dfs(nums, f, tar - x as usize);
            }
            f[tar]
        }
        dfs(&nums, &mut f, target as usize)
    }
}
