package sbgo

func partitionDisjoint(nums []int) int {
  n := len(nums)
  max := func(i, j int) int {
    if i < j {
      return j
    }
    return i
  } 
  min := func(i, j int) int {
    if i < j {
      return i
    }
    return j
  }
  lmx, rmn := make([]int, n), make([]int, n)
  lmx[0], rmn[n - 1] = nums[0], nums[n - 1]
  for i := 1;i < n;i++ {
    lmx[i] = max(lmx[i - 1], nums[i])
  }
  for i := n - 2;i >= 0;i-- {
    rmn[i] = min(rmn[i + 1], nums[i])
  }
  ans := 1
  for i := 0;i < n - 1;i++ {
    if lmx[i] <= rmn[i + 1] {
      break
    }
    ans++
  }
  return ans
}
