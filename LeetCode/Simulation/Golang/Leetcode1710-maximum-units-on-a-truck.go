package sbgo

import "sort"

func maximumUnits(boxTypes [][]int, truckSize int) int {
	sort.Slice(boxTypes, func(i, j int) bool {
		return boxTypes[i][1] > boxTypes[j][1]
	})
	ans := 0
	for _, x := range boxTypes {
		if x[0] >= truckSize {
			ans += truckSize * x[1]
			break
		}
		ans += x[0] * x[1]
		truckSize -= x[0]
	}
	return ans
}
