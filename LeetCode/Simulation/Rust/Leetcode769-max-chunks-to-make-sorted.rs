impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let (mut res, mut mx) = (0,0);
        for i in 0..n {
            mx = mx.max(arr[i]);
            if mx == i as i32 {
                res += 1;
            }
        }
        res
    }
}
