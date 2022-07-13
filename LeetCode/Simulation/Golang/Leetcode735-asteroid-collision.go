package sbgo

func asteroidCollision(asteroids []int) []int {
	ans := []int{}
	for _, ast := range asteroids {
		flag := true
		for flag && len(ans) != 0 && ans[len(ans)-1] > 0 && ast < 0 {
			flag = -ast > ans[len(ans)-1]
			if -ast >= ans[len(ans)-1] {
				ans = ans[0 : len(ans)-1]
			}
		}
		if flag {
			ans = append(ans, ast)
		}
	}
	return ans
}
