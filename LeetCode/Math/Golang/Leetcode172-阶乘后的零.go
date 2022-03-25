package sbgo

/*
	阶乘分解，找2和5的幂次，5肯定少于2
	找到5的幂次：
		1. 5 => res += n / 5, n/= 5
		2. 5 ** 2,在上面基础上纳入少算5 ** 2的一个5，res += n / 5,n /= 5
		...
*/

func trailingZeroes(n int) int {
	res := 0
	for n != 0 {
		res += n / 5
		n /= 5
	}
	return res
}
