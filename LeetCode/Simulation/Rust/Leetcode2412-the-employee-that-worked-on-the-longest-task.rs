impl Solution {
    pub fn hardest_worker(n: i32, logs: Vec<Vec<i32>>) -> i32 {
        let (mut mx, mut id, m, mut pre) = (0, n, logs.len(), 0);
        for i in 0..m {
            let diff = logs[i][1] - pre;
            if diff > mx {
                mx = diff;
                id = logs[i][0];
            } else if mx == diff {
                id = id.min(logs[i][0]);
            }
            pre = logs[i][1];
        }
        id
    }
}