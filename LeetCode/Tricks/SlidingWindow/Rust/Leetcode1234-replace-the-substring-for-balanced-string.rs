impl Solution {
    pub fn balanced_string(s: String) -> i32 {
        let get = |c : u8| -> usize {
            if c == b'Q' {
                return 0;
            }
            if c == b'W' {
                return 1;
            }
            if c == b'E' {
                return 2;
            }
            3
        };
        let mut tot = vec![0;4];
        for &c in s.as_bytes() {
            tot[get(c)] += 1;
        }
        let n = s.len();
        if tot[0] == n / 4 && tot[1] == n / 4 && tot[2] == n / 4 && tot[3] == n / 4 {
            return 0;
        }
        let mut sum = vec![0;4];
        let mut j = 0;
        let mut res = n;
        let s = s.as_bytes();
        // 窗口之内的字母删了，窗口外面的要能<= n / 4,这样才能按照需求填满窗口内的
        let check = |tot: &Vec<usize>, sum: &Vec<usize>|-> bool {
            for i in 0..4 {
                if tot[i] - sum[i] > n / 4 {
                    return false;
                }
            }
            true
        };
        for i in 0..n {
            sum[get(s[i])] += 1;
            while j <= i && check(&tot, &sum) {
                res = res.min(i - j + 1);
                sum[get(s[j])] -= 1;
                j += 1;
            }
        }
        res as i32
    }
}


