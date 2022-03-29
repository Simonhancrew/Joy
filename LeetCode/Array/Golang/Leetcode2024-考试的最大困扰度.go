package sbgo

func maxConsecutiveAnswers(answerKey string, k int) int {
	n, cnt0, cnt1, ans := len(answerKey), 0, 0, 0
	for l, r := 0, 0; r < n; r++ {
		if answerKey[r] == 'T' {
			cnt1++
		} else {
			cnt0++
		}
		for l < r && min(cnt0, cnt1) > k {
			if answerKey[l] == 'T' {
				cnt1--
			} else {
				cnt0--
			}
			l++
		}
		ans = max(ans, r-l+1)
	}
	return ans
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
