use std::collections::VecDeque;
impl Solution {
    pub fn max_task_assign(mut tasks: Vec<i32>, mut workers: Vec<i32>, pills: i32, strength: i32) -> i32 {
        let (mut l, mut r) = (0, tasks.len().min(workers.len()) + 1);
        tasks.sort_unstable();
        workers.sort_unstable();
        let m = workers.len();
        let check = |k:usize| -> bool {
            let mut q = VecDeque::new();
            let (mut i, mut p) = (0, pills);
            for j in m-k..m {
                let w = workers[j];
                while i < k && w + strength >= tasks[i] {
                    q.push_back(tasks[i]);
                    i += 1;
                }
                if q.is_empty() {
                    return false;
                }
                if w >= *q.front().unwrap() {
                    q.pop_front();
                    continue;
                }
                if p == 0 {
                    return false;
                }
                p -= 1;
                q.pop_back();
            }
            true
        };
        while (l + 1 < r) {
            let mid = l + r >> 1;
            if check(mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        l as i32
    }
}