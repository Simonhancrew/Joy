package sbgo

type void struct{}

func numUniqueEmails(emails []string) int {
	st := map[string]void{}
	for _, s := range emails {
		t := ""
		for i := 0; i < len(s); i++ {
			if s[i] == '.' {
				continue
			}
			if s[i] == '@' {
				t += s[i:]
				break
			}
			if s[i] == '+' {
				for s[i] != '@' {
					i++
				}
				t += s[i:]
				break
			}
			t += s[i : i+1]
		}
		st[t] = void{}
	}
	return len(st)
}
