impl Solution {
    pub fn trim_mean(mut arr: Vec<i32>) -> f64 {
        arr.sort();
        let n = arr.len();
        let mut acc = 0;
        for i in (n / 20)..((n * 19) / 20) {
            acc += arr[i];
        }
        acc as f64 / (0.9 * n as f64)
    }
}
