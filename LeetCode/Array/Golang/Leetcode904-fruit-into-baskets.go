package sbgo

func totalFruit(fruits []int) int {
  mp,n,res := map[int]int{}, len(fruits), 0
  max := func(i,j int) int {
    if i < j {
      return j
    }
    return i
  }
  for i, j, s := 0, 0, 0;i < n;i++ {
    mp[fruits[i]]++
    if mp[fruits[i]] == 1 {
      s++
    }
    for s > 2 {
      mp[fruits[j]]--
      if mp[fruits[j]] == 0 {
        s--
      }
      j++
    }
    res = max(res, i - j + 1)
  }
  return res
}


