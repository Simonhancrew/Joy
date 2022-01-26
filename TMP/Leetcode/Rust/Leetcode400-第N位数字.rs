impl Solution {
    pub fn find_nth_digit(mut n: i32) -> i32 {
        let mut n = n as i64;
        let (mut cnt,mut base,mut s) = (1,9 as i64,1 as i64);
        while n > base * cnt{
            n -= base * cnt;
            cnt += 1;
            base *= 10;
            s *= 10;
        }
        s += (n + cnt - 1) / cnt - 1;
        if n % cnt == 0 {
            n = cnt;
        } else{
            n = n % cnt;
        }
        (s.to_string().as_bytes()[n as usize - 1] - b'0') as i32
    }
}