package sbgo

/*
	go的type和construct
	type struct_variable_type struct {
		member definition
		member definition
		...
		member definition
	}
	声明有两种，一种顺序声明，另外一种冒号分隔，具体指定
	构造函数一般传指针出去，函数具体修改的话是需要传指针进去的，和c一样
	然后结构体可以内嵌，但如果字段冲突要指名具体的namespace
*/

type PeekingIterator struct {
	it    *Iterator
	hasne bool
	cur   int
}

func Constructor(iter *Iterator) *PeekingIterator {
	return &PeekingIterator{iter, iter.hasNext(), iter.next()}
}

func (iter *PeekingIterator) hasNext() bool {
	return iter.hasne
}

func (iter *PeekingIterator) next() int {
	t := iter.cur
	iter.hasne = iter.it.hasNext()
	iter.cur = iter.it.next()
	return t
}

func (iter *PeekingIterator) peek() int {
	return iter.cur
}
