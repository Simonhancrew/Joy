package sbgo

func numComponents(head *ListNode, nums []int) int {
	in, res := false, 0
	st := map[int]bool{}
	for _, val := range nums {
		st[val] = true
	}
	for head != nil {
		if st[head.Val] {
			if !in {
				in = true
				res++
			}
		} else {
			in = false
		}
		head = head.Next
	}
	return res
}
