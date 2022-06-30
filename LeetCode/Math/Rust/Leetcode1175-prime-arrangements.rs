impl Solution {
    pub fn num_prime_arrangements(n: i32) -> i32 {
        let (P, mut st, mut primes) = (1e9 as i64 + 7, vec![false; n as usize + 1], vec![]);
        for i in 2..=n {
            if !st[i as usize] {
                primes.push(i);
            }
            let mut j = 0;
            while primes[j] <= n / i {
                st[(primes[j] * i) as usize] = true;
                if i % primes[j] == 0 {
                    break;
                }
                j += 1;
            }
        }
        let cnt = primes.len();
        let fact = |n: i32| -> i64 {
            let mut res: i64 = 1;
            for i in 1..=n {
                res = res * i as i64 % P;
            }
            res
        };

        (fact(n - cnt as i32) * fact(cnt as i32) % P) as i32
    }
}
