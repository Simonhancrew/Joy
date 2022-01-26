package sbgo

import "math"

func poorPigs(buckets int, minutesToDie int, minutesToTest int) int {
	k := minutesToTest / minutesToDie
	return int(math.Ceil(math.Log(float64(buckets)) / math.Log(float64(k+1))))
}
