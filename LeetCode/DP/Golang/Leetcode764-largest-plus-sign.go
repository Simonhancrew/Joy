package sbgo

func orderOfLargestPlusSign(n int, mines [][]int) int {
  f,g := make([][]int, n), make([][]bool, n)
  for i := 0;i < n;i++ {
    f[i] = make([]int, n)
    g[i] = make([]bool, n)
    for j := 0;j < n;j++ {
      g[i][j] = true
    }
  }
  for _, x := range mines {
    g[x[0]][x[1]] = false
  }

  for i := 0;i < n;i++ {
    for j, s := 0, 0;j < n;j++ {
      if g[i][j] {
        s++
      } else {
        s = 0
      }
      f[i][j] = s
    }
  }
  min := func(i, j int) int {
    if i < j {
      return i
    }
    return j
  }
  for i := 0;i < n;i++ {
    for j, s := n - 1, 0;j >= 0;j-- {
      if g[i][j] {
        s++;
      } else {
        s = 0
      }
      f[i][j] = min(f[i][j], s)
    }
  }
  
  for j := 0;j < n;j++ {
    for i, s := 0, 0;i < n;i++ {
      if g[i][j] {
        s++;
      } else {
        s = 0
      }
      f[i][j] = min(f[i][j], s)
    }
  }
  
  for j := 0;j < n;j++ {
    for i, s := n - 1, 0;i >= 0;i-- {
      if g[i][j] {
        s++
      } else {
        s = 0
      }
      f[i][j] = min(f[i][j], s)
    }
  }
  res := 0
  max := func(i, j int) int {
    if i < j {
      return j
    }
    return i
  }
  for i := 0;i < n;i++ {
    for j := 0;j < n;j++ {
      res = max(f[i][j], res)
    }
  }
  return res
}
