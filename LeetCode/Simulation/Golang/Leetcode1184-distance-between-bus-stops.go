package sbgo

func distanceBetweenBusStops(distance []int, start int, destination int) int {
	if start > destination {
		start, destination = destination, start
	}
	s1, s2 := 0, 0
	for i := 0; i < len(distance); i++ {
		if i >= start && i < destination {
			s1 += distance[i]
		} else {
			s2 += distance[i]
		}
	}
	return min(s1, s2)
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
