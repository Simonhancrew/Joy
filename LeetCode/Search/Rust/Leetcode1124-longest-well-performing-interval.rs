impl Solution {
    pub fn longest_wpi(hours: Vec<i32>) -> i32 {
        let n = hours.len();
        let mut s = vec![0;n + 1];
        for i in 1..=n {
            s[i] = s[i - 1] + if hours[i - 1] > 8 {
                1
            } else {
                -1
            }
        }
        let mut res = 0;
        let mut stk = vec![0];
        for i in 1..=n {
            let (mut l, mut r) = (0, stk.len() - 1);
            while l < r {
                let mid = (l + r) >> 1;
                if s[i] > s[stk[mid]] {
                    r = mid
                } else {
                    l = mid + 1;
                }
            }
            if s[i] > s[stk[l]] {
                res = res.max(i - stk[l]);
            }
            if s[i] < s[stk[stk.len() - 1]] {
                stk.push(i);
            }
        }
        res as i32
    }   
}

