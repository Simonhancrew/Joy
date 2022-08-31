package sbgo

func validateStackSequences(pushed []int, popped []int) bool {
  ans,n := []int{},len(pushed)
  for i,j := 0,0;i < n;i++ {
    ans = append(ans,pushed[i])
    for len(ans) != 0 && ans[len(ans) - 1] == popped[j] {
      j++
      ans = ans[:len(ans) - 1]
    }
  }
  return len(ans) == 0
}
