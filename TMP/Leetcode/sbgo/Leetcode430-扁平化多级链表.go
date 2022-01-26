package sbgo

func flatten(root *Node) *Node {
	t := root
	for t != nil {
		ne := t.Next
		if t.Child != nil {
			t.Next = flatten(t.Child)
			t.Next.Prev = t
			t.Child = nil
			for t.Next != nil {
				t = t.Next
			}
		}
		t.Next = ne
		if ne != nil {
			ne.Prev = t
		}
		t = ne
	}
	return root
}

type Node struct {
	Val   int
	Prev  *Node
	Next  *Node
	Child *Node
}
