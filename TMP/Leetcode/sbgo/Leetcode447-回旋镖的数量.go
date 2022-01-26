package sbgo

// 组合数

func numberOfBoomerangs(points [][]int) int {
	res := 0
	for _, p := range points {
		mp := make(map[int]int)
		for _, q := range points {
			dis := (p[0]-q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1])
			mp[dis]++
		}
		for _, v := range mp {
			res += (v - 1) * v
		}
	}
	return res
}
