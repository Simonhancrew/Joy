package sbgo

type void struct{}

func containsNearbyDuplicate(nums []int, k int) bool {
	st := map[int]void{}
	for i := 0; i < len(nums); i++ {
		if i > k {
			delete(st, nums[i-k-1])
		}
		if _, has := st[nums[i]]; has {
			return true
		}
		st[nums[i]] = void{}
	}
	return false
}
