package sbgo

type void struct{}

var mem void

func uniqueMorseRepresentations(words []string) int {
	st := make(map[string]void)
	pos := []string{
		".-", "-...", "-.-.", "-..", ".",
		"..-.", "--.", "....", "..", ".---",
		"-.-", ".-..", "--", "-.", "---",
		".--.", "--.-", ".-.", "...", "-",
		"..-", "...-", ".--", "-..-", "-.--", "--..",
	}
	for _, word := range words {
		s := ""
		for _, x := range word {
			s += pos[x-'a']
		}
		st[s] = mem
	}
	return len(st)
}
