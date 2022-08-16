package sbgo

type OrderedStream struct {
	mp  map[int]string
	ptr int
}

func Constructor(n int) OrderedStream {
	mp := map[int]string{}
	return OrderedStream{mp, 1}
}

func (this *OrderedStream) Insert(idKey int, value string) []string {
	this.mp[idKey] = value
	ans := []string{}
	if _, ok := this.mp[this.ptr]; !ok {
		return ans
	}
	for value, ok := this.mp[this.ptr]; ok; value, ok = this.mp[this.ptr] {
		if !ok {
			break
		}
		ans = append(ans, value)
		this.ptr++
	}
	return ans
}
