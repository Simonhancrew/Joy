package sbgo

import "strconv"

func magicalString(n int) int {
  s := "122"
  for i, k := 2, 1;len(s) < n;i,k = i + 1, 3 - k {
    for j := 0;j < int(s[i] - '0');j++ {
      s += strconv.Itoa(k)
    }
  }
  res := 0
  for i := 0;i < n;i++ {
    if s[i] == '1' {
      res++
    }
  }
  return res
}
