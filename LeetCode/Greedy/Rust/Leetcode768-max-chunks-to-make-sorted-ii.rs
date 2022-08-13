use std::collections::HashMap;
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let (mut b, n, mut mp) = (arr.clone(), arr.len(), HashMap::new());
        b.sort();
        let (mut s, mut res) = (0, 0);
        for i in 0..n {
            let v = mp.entry(arr[i]).or_insert(0);
            if *v == 1 {
                s -= 1;
            } else if *v == 0 {
                s += 1;
            }
            *v -= 1;
            let v = mp.entry(b[i]).or_insert(0);
            if *v == -1 {
                s -= 1;
            } else if *v == 0 {
                s += 1;
            }
            *v += 1;
            if s == 0 {
                res += 1;
            }
        }
        res
    }
}
