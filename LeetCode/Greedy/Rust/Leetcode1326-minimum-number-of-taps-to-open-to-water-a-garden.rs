impl Solution {
    pub fn min_taps(n: i32, ranges: Vec<i32>) -> i32 {
        let mut rec = vec![];
        for i in 0..ranges.len() {
            rec.push(vec![i as i32 - ranges[i], i as i32 + ranges[i]]);
        }
        rec.sort_unstable();
        let mut i = 0;
        let (mut res, mut r) = (0, 0);
        while i < rec.len() {
            let (mut j, mut mr) = (i, -1);
            while j < rec.len() && rec[j][0] <= r {
                mr = mr.max(rec[j][1]);
                j += 1;
            }
            if mr == -1 {
                return -1
            }
            res += 1;
            if mr >= n {
                return res;
            }
            r = mr;
            i = j
        }
        -1
    }
}
