package sbgo

import "sort"

func advantageCount(nums1 []int, nums2 []int) []int {
  n := len(nums1)
  id,ans := make([]int,n), make([]int,n)
  for i := 0; i < n;i++ {
    id[i] = i
  }
  sort.Ints(nums1)
  sort.Slice(id,func(i,j int) bool {
    return nums2[id[i]] < nums2[id[j]]
  })
  // fmt.Println(id)
  l,r := 0, n - 1;
  for i := 0;i < n;i++ {
    if nums1[i] > nums2[id[l]] {
      ans[id[l]] = nums1[i]
      l++
    } else {
      ans[id[r]] = nums1[i]
      r--
    }
  }
  return ans
}
