package sbgo

func largestComponentSize(nums []int) int {
	n, res := len(nums), 1
	pa, cnt := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		pa[i] = i
		cnt[i] = 1
	}
	var find func(int) int
	find = func(x int) int {
		if pa[x] != x {
			pa[x] = find(pa[x])
		}
		return pa[x]
	}
	app := map[int][]int{}
	for i := 0; i < n; i++ {
		x := nums[i]
		for j := 1; j <= x/j; j++ {
			if x%j == 0 {
				if j > 1 {
					app[j] = append(app[j], i)
				}
				app[x/j] = append(app[x/j], i)
			}
		}
	}
	for _, v := range app {
		for i := 1; i < len(v); i++ {
			a, b := v[0], v[i]
			if find(a) != find(b) {
				cnt[find(a)] += cnt[find(b)]
				pa[find(b)] = find(a)
				if res < cnt[find(a)] {
					res = cnt[find(a)]
				}
			}
		}
	}
	return res
}
