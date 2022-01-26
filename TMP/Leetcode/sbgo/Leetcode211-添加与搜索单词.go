package sbgo

type Node struct {
	Child [26]*Node
	Isend bool
}

type WordDictionary struct {
	Root *Node
}

func Constructor() WordDictionary {
	return WordDictionary{&Node{}}
}

func (p *WordDictionary) AddWord(word string) {
	t := p.Root
	for _, c := range word {
		c -= 'a'
		if t.Child[c] == nil {
			t.Child[c] = &Node{}
		}
		t = t.Child[c]
	}
	t.Isend = true
}

func (p *WordDictionary) Search(word string) bool {

	var dfs func(*Node, int) bool
	dfs = func(p *Node, idx int) bool {
		if idx == len(word) {
			return p.Isend
		}
		if word[idx] == '.' {
			for i := 0; i < 26; i++ {
				if p.Child[i] != nil && dfs(p.Child[i], idx+1) {
					return true
				}
			}
		} else {
			c := word[idx] - 'a'
			if p.Child[c] != nil {
				return dfs(p.Child[c], idx+1)
			}
		}
		return false
	}
	return dfs(p.Root, 0)
}
