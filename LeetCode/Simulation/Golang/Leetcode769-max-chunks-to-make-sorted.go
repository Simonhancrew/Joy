package sbgo

func maxChunksToSorted(arr []int) int {
  res, mx := 0, 0
  max := func(i,j int) int {
    if i < j {
      return j
    }
    return i
  }
  for i, val := range arr {
    mx = max(mx, val)
    if mx == i {
      res++
    }
  }
  return res
}
