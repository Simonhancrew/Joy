package sbgo

func ambiguousCoordinates(s string) []string {
  s = s[1:len(s) - 1]
  res := []string{}
  get := func(s string) []string {
    res := []string{}
    if len(s) == 1 || s[0] != '0' {
      res = append(res, s)
    }
    for i := 1;i < len(s);i++ {
      l,r := s[:i], s[i:]
      if len(l) > 1 && l[0] == '0' {
        continue
      }
      if r[len(r) - 1] == '0' {
        continue
      }
      res = append(res, l + "." + r)
    }
    return res
  }
  for i := 1;i < len(s);i++ {
    l, r := get(s[0:i]), get(s[i:])
    for _, x := range l {
      for _, y := range r {
        res = append(res, "(" + x + ", " + y + ")")
      }
    }
  }
  return res
}
