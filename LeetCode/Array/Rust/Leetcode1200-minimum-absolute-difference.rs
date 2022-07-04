impl Solution {
    pub fn minimum_abs_difference(mut arr: Vec<i32>) -> Vec<Vec<i32>> {
        arr.sort();
        let (mut res, mut n, mut mini) = (vec![], arr.len(), i32::MAX);
        for i in 0..n - 1 {
            let mut diff = arr[i + 1] - arr[i];
            if diff == mini {
                res.push(vec![arr[i], arr[i + 1]]);
            } else if diff < mini {
                mini = diff;
                res = vec![vec![arr[i], arr[i + 1]]];
            }
        }
        res
    }
}
