package sbgo

func sumSubarrayMins(arr []int) int {
  n := len(arr)
  l, r, stk := make([]int, n), make([]int, n), []int{}
  for i := 0;i < n;i++ {
    for len(stk) != 0 && arr[stk[len(stk) - 1]] > arr[i] {
      stk = stk[:len(stk) - 1]
    }
    if len(stk) == 0 {
      l[i] = -1
    } else {
      l[i] = stk[len(stk) - 1]
    }
    stk = append(stk, i)
  }
  stk = []int{}
  for i := n - 1;i >= 0;i-- {
    for len(stk) != 0 && arr[stk[len(stk) - 1]] >= arr[i] {
      stk = stk[:len(stk) - 1];
    }
    if len(stk) == 0 {
      r[i] = n;
    } else {
      r[i] = stk[len(stk) - 1];
    }
    stk = append(stk, i)
  }
  res, mod := 0, int(1e9 + 7)
  for i := 0;i < n;i++ {
    res = (res + arr[i] * (i - l[i]) * (r[i] - i)) % mod
  } 
  return res
}
