package sbgo

func minSwap(nums1 []int, nums2 []int) int {
	min := func(i, j int) int {
		if i < j {
			return i
		}
		return j
	}
	n := len(nums1)
	f := make([][]int, n)
	for i := 0; i < n; i++ {
		f[i] = make([]int, 2)
		if i == 0 {
			f[i][0] = 0
			f[i][1] = 1
		} else {
			f[i][0] = int(1e9)
			f[i][1] = int(1e9)
		}
	}
	for i := 1; i < n; i++ {
		if nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1] {
			f[i][0] = min(f[i][0], f[i-1][0])
			f[i][1] = min(f[i][1], f[i-1][1]+1)
		}
		if nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1] {
			f[i][0] = min(f[i][0], f[i-1][1])
			f[i][1] = min(f[i][1], f[i-1][0]+1)
		}
	}
	return min(f[n-1][1], f[n-1][0])
}
