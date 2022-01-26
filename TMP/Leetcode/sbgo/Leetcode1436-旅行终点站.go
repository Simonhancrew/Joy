package sbgo

func destCity(paths [][]string) string {
	out := map[string]bool{}
	for _, path := range paths {
		out[path[0]] = true
	}
	for _, path := range paths {
		if !out[path[1]] {
			return path[1]
		}
	}
	return ""
}
