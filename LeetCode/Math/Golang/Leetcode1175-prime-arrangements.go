package sbo

func numPrimeArrangements(n int) int {
    primes,st := []int{},make([]bool,n + 1)
    for i := 2;i <= n;i++ {
        if !st[i] {
            primes = append(primes,i)
        }
        for j := 0;primes[j] <= n / i;j++ {
            st[primes[j] * i] = true
            if i % primes[j] == 0 {
                break
            }
        }
    }
    cnt := len(primes)
    const P = 1e9 + 7
    fact := func(n int) int {
        res := 1
        for i := 1;i <= n;i++ {
            res = res * i % P
        }
        return res
    }
    return fact(n - cnt) * fact(cnt) % P
}