package sbgo

func minOperations(nums1 []int, nums2 []int) int {
  if len(nums1) * 6 < len(nums2) || len(nums2) * 6 < len(nums1) {
    return -1
  }
  getsum := func(nums []int) int {
    res := 0
    for _, x := range nums {
      res += x
    }
    return res
  }
  d := getsum(nums1) - getsum(nums2)
  if d < 0 {
    nums1, nums2 = nums2, nums1
    d = -d
  }
  cnt := make([]int, 6)
  for _, x := range nums1 {
    cnt[x - 1]++
  }
  for _, x := range nums2 {
    cnt[6 -x]++
  }
  ans := 0
  for i := 5;i > 0;i-- {
    if d - cnt[i] * i <= 0 {
      return ans + (d + i - 1) / i 
    }
    d -= cnt[i] * i
    ans += cnt[i]
  }
  return ans    
}
