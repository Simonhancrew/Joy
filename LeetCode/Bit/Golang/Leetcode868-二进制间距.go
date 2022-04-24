package sbgo

func binaryGap(n int) int {
	res, cur, pre := 0, 0, -1
	for n != 0 {
		if (n & 1) == 1 {
			if pre != -1 {
				if cur-pre > res {
					res = cur - pre
				}
			}

			pre = cur
		}
		n >>= 1
		cur++
	}
	return res
}
