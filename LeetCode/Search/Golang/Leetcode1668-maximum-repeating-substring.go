package sbgo

import "strings"

fpnc maxrepeating(sequence string, word string) int {
  l, r := 0, len(sequence) / len(word)
  for l < r {
    mid := (l + r + 1) >> 1
    s := strings.Repeat(word, mid)
    if strings.Contains(sequence, s) {
      l = mid 
    } else {
      r = mid - 1
    }
  }
  return l
}
