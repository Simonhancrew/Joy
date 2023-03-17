impl Solution {
    pub fn answer_queries(mut nums: Vec<i32>,mut queries: Vec<i32>) -> Vec<i32> {
        let mut res = vec![0;queries.len()];
        nums.sort_unstable();
        let n = nums.len();
        for i in 0..queries.len() {
            let mut cur = 0;
            for j in 0..n {
                if queries[i] >= nums[j] {
                    queries[i] -= nums[j];
                    cur += 1;
                } else {
                    break;
                }
            }
            res[i] = cur;
        }
        res
    }
}
