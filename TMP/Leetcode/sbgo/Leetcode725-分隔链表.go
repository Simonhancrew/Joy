package sbgo

func splitListToParts(head *ListNode, k int) []*ListNode {
	n, p := 0, head
	for p != nil {
		n++
		p = p.Next
	}
	p = head
	ans := []*ListNode{}
	for i := 0; i < k; i++ {
		base, mod := n/k, n%k
		if i+1 <= mod {
			base++
		}
		ans = append(ans, p)
		for j := 0; j < base-1; j++ {
			p = p.Next
		}
		if p != nil {
			q := p.Next
			p.Next = nil
			p = q
		}
	}
	return ans
}
