package sbgo

import "strings"

func simplifyPath(path string) string {
	res := []string{}
	for _, name := range strings.Split(path, "/") {
		if name == ".." {
			if len(res) > 0 {
				res = res[:len(res)-1]
			}
		} else if name != "" && name != "." {
			res = append(res, name)
		}
	}
	return "/" + strings.Join(res, "/")
}
