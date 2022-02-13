package sbgo

func maxNumberOfBalloons(text string) int {
	cnt := make([]int, 5)
	for i := 0; i < len(text); i++ {
		if text[i] == 'b' {
			cnt[0]++
		} else if text[i] == 'a' {
			cnt[1]++
		} else if text[i] == 'l' {
			cnt[2]++
		} else if text[i] == 'o' {
			cnt[3]++
		} else if text[i] == 'n' {
			cnt[4]++
		}
	}
	cnt[2] /= 2
	cnt[3] /= 2
	ans := cnt[0]
	for _, v := range cnt {
		if v < ans {
			ans = v
		}
	}
	return ans
}
