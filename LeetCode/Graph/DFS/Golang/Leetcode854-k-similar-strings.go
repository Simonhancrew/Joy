package sbgo

func kSimilarity(str1 string, str2 string) int {
  if str1 == str2 {
    return 0
  }
  n,dep := len(s1), 1
  s1,s2 := []byte(str1),[]byte(str2)
  f := func(s1,s2 []byte) int {
    res := 0
    for i := 0;i < n;i++ {
      if s1[i] != s2[i] {
        res ++
      }
    }
    return (res + 1) / 2
  }
  var dfs func(s1,s2 []byte,dep int) bool 
  dfs = func(s1,s2 []byte, dep int) bool {
    if dep == 0 {
      return string(s1) == string(s2)
    }
    if f(s1,s2) > dep {
      return false
    }
    for i := 0;i < n;i++ {
      if s1[i] != s2[i] {
        for j := i + 1;j < n;j++ {
          if s2[i] == s1[j] {
            s1[i],s1[j] = s1[j],s1[i]
            if dfs(s1,s2,dep - 1) {
              return true
            }
            s1[i],s1[j] = s1[j],s1[i]
          }
        }
        break
      }
    }
    return false
  }

  for !dfs(s1,s2,dep) {
    dep++
  }
  return dep
}
