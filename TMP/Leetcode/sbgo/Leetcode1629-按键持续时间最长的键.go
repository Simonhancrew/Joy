package sbgo

func slowestKey(releaseTimes []int, keysPressed string) byte {
	ans, time := keysPressed[0], releaseTimes[0]
	for i := 1; i < len(keysPressed); i++ {
		t := releaseTimes[i] - releaseTimes[i-1]
		if t > time || (t == time && ans < keysPressed[i]) {
			ans, time = keysPressed[i], t
		}
	}
	return ans
}
