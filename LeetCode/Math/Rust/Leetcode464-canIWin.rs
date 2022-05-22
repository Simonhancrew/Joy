impl Solution {
    pub fn can_i_win(max_choosable_integer: i32, desired_total: i32) -> bool {
        let (n, m) = (max_choosable_integer, desired_total);
        if n * (n + 1) / 2 < m {
            return false;
        }
        let mut f = vec![-1; 1 << n];
        if Solution::dp(&mut f, 0, n, m) == 1 {
            return true;
        }
        false
    }
    fn dp(f: &mut Vec<i8>, x: usize, n: i32, m: i32) -> i8 {
        if f[x] != -1 {
            return f[x];
        }
        let mut sum = 0;
        for i in 0..n {
            if (x >> i) & 1 == 1 {
                sum += i + 1;
            }
        }
        for i in 0..n {
            if (x >> i) & 1 == 1 {
                continue;
            }
            if sum + i + 1 >= m {
                f[x] = 1;
                return 1;
            }
            if Solution::dp(f, x + (1 << i), n, m) == 0 {
                f[x] = 1;
                return 1;
            }
        }
        f[x] = 0;
        0
    }
}
