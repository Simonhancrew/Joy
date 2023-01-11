package sbgo

func digitCount(num string) bool {
  mp := make([]int, 10)
  for _, c := range num {
    mp[c - '0']++
  }
  for i := 0;i < len(num);i++ {
    cnt := num[i] - '0'
    if int(cnt) != mp[i] {
      return false
    }
  }
  return true
}
