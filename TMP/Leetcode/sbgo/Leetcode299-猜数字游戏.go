package sbgo

import "strconv"

func getHint(secret string, guess string) string {
	bull, cow := 0, 0
	st := make([]int, 26)
	for i := 0; i < len(secret); i++ {
		if guess[i] == secret[i] {
			bull++
		} else {
			st[secret[i]-'0']++
		}
	}
	for i := 0; i < len(guess); i++ {
		if guess[i] != secret[i] && st[guess[i]-'0'] > 0 {
			cow++
			st[guess[i]-'0']--
		}
	}
	return strconv.Itoa(bull) + "A" + strconv.Itoa(cow) + "B"
}
