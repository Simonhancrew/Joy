package sbgo

func missingTwo(nums []int) []int {
  n,acc,ans := len(nums) + 2, 0, []int{0,0}
  for _,num := range nums {
    acc ^= num
  } 
  for i := 1;i <= n;i++ {
    acc ^= i
  }
  lowbit := acc & (-acc)
  for _,num := range nums {
    if lowbit & num != 0 {
      ans[0] ^= num
    }else {
      ans[1] ^= num
    }
  }
  for i := 1;i <= n;i++ {
    if lowbit & i != 0 {
      ans[0] ^= i
    }else {
      ans[1] ^= i
    }
  }
  return ans
}
